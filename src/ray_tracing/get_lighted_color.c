/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lighted_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:09:32 by margot            #+#    #+#             */
/*   Updated: 2022/11/30 17:52:55 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	is_in_shadow(t_world world, t_tuple point, t_point_light *light)
{
	double					distance;
	t_tuple					direction;
	t_ray					ray;
	t_w_intersections		w_intersections;
	t_hit					hit;

	distance = tuple_len(sub_tuples(light->position, point));
	ray.direction = normalize_tuple(sub_tuples(light->position, point));
	ray.origin = point;
	w_intersections = get_world_intersections(world, ray);
	hit = find_w_hit(w_intersections);
	if (hit.does_hit == true && hit.i + EPSILON < distance)
		return (true);
	return (false);
}

static t_color	get_final_specular_color(t_ray_pcomp_tool pcomp,
		t_point_light *light)
{
	t_color	specular_color;
	t_tuple	lightv;
	t_tuple	reflectv;
	double	reflect_dot_eye;
	double	factor;

	lightv = normalize_tuple(sub_tuples(light->position, pcomp.over_i));
	reflectv = ft_reflect_in(neg_tuple(lightv), pcomp.normalv);
	reflect_dot_eye = dot_product(reflectv, pcomp.eyev);
	if (reflect_dot_eye <= 0)
		specular_color = create_color(0, 0, 0);
	else
	{
		factor = pow(reflect_dot_eye, pcomp.object->material.shininess);
		specular_color = scale_color(scale_color(light->intensity,
					pcomp.object->material.specular), factor);
	}
	return (specular_color);
}

static t_color	get_final_diffuse_color( t_material material,
	double light_dot_normal, t_point_light *light)
{
	t_color	effective_color;
	t_color	diffuse_color;

	effective_color = multiply_colors(material.color, light->intensity);
	diffuse_color = scale_color(effective_color,
			material.diffuse * light_dot_normal);
	return (diffuse_color);
}

static double	compute_light_dot_normal(t_ray_pcomp_tool pcomp,
		t_point_light *light)
{
	t_tuple	lightv;
	double	light_dot_normal;

	lightv = normalize_tuple(sub_tuples(light->position, pcomp.i));
	light_dot_normal = dot_product(lightv, pcomp.normalv);
	return (light_dot_normal);
}

t_color	get_lighted_color(t_world world, t_point_light *light,
		t_ray_pcomp_tool pcomp)
{
	double			light_dot_normal;
	t_color			ambient_color;
	t_color			diffuse_color;
	t_color			specular_color;

	ambient_color = multiply_colors(pcomp.object->material.color,
			world.ambient_light);
	light_dot_normal = compute_light_dot_normal(pcomp, light);
	pcomp.over_i = add_tuples(pcomp.i, scale_tuple(pcomp.normalv, ACNE));
	if (pcomp.object->material.texture_type == PATTERN_TEXTURE_TYPE)
		pcomp.object->material.color = checker_at_object(
				pcomp.object->material.pattern, *pcomp.object, pcomp.over_i);
	if (light_dot_normal < 0 || is_in_shadow(world, pcomp.over_i, light))
	{
		diffuse_color = create_color(0, 0, 0);
		specular_color = create_color(0, 0, 0);
	}
	else
	{
		diffuse_color = get_final_diffuse_color(pcomp.object->material,
				light_dot_normal, light);
		specular_color = get_final_specular_color(pcomp, light);
	}
	return (add_colors(add_colors(ambient_color, diffuse_color),
			specular_color));
}
