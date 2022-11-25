/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lighted_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:09:32 by margot            #+#    #+#             */
/*   Updated: 2022/11/25 15:56:17 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_tuple	reflect_in(t_tuple in, t_tuple normal)
{
	return (ft_sub_tuples(in, ft_scale_tuple(normal, 2.0 * ft_tuple_scalarproduct(in, normal))));
}

bool	is_in_shadow(t_world world, t_tuple point)
{
	t_tuple					v;
	double					distance;
	t_tuple					direction;
	t_ray					ray;
	t_w_intersections	w_intersections;
	t_hit				hit;

	v = ft_sub_tuples(((t_point_light *)world.point_lights->content)->position, point);
	distance = ft_tuple_len(v);
	ray.direction = ft_normalize_tuple(v);
	ray.origin = point;
	w_intersections = compute_world_intersections(world, ray);
	hit = find_w_hit(w_intersections);
	if (hit.does_hit == true && hit.i < distance)
		return (true);
	return (false);
}

static t_color	get_final_specular_color(t_pcomp_tool pcomp, t_point_light *light)
{
	t_color	specular_color;
	t_tuple	lightv;
	t_tuple	reflectv;
	double	reflect_dot_eye;
	double	factor;

	lightv = ft_normalize_tuple(ft_sub_tuples(light->position, pcomp.i));
	reflectv = reflect_in(ft_neg_tuple(lightv), pcomp.normalv);
	reflect_dot_eye = ft_tuple_scalarproduct(reflectv, pcomp.eyev);
	if (reflect_dot_eye <= 0)
		specular_color = create_color(0, 0, 0);
	else
	{
		factor = pow(reflect_dot_eye, pcomp.object->material.shininess);
		specular_color = ft_scale_color(ft_scale_color(light->intensity, pcomp.object->material.specular), factor);
	}
	return (specular_color);
}

static t_color	get_final_diffuse_color( t_material material,
	double light_dot_normal, t_point_light *light)
{
	t_color	effective_color;
	t_color	diffuse_color;

	effective_color = ft_multiply_colors(material.color, light->intensity);
	diffuse_color = ft_scale_color(effective_color, material.diffuse * light_dot_normal);
	return (diffuse_color);
}

static double	compute_light_dot_normal(t_pcomp_tool pcomp, t_point_light *light)
{
	t_tuple	lightv;
	double	light_dot_normal;

	lightv = ft_normalize_tuple(ft_sub_tuples(light->position, pcomp.i));
	light_dot_normal = ft_tuple_scalarproduct(lightv, pcomp.normalv);
	return (light_dot_normal);
}

static t_color	get_final_ambient_color(t_material material, t_point_light *light)
{
	t_color	effective_color;
	t_color	ambient_color;

	effective_color = ft_multiply_colors(material.color, light->intensity);
	ambient_color = ft_scale_color(effective_color, material.ambient);
	return (ambient_color);
}

t_color	get_lighted_color(t_world world, t_pcomp_tool pcomp)
{
	t_point_light	*light_tmp;
	double			light_dot_normal;
	t_color			ambient_color;
	t_color			diffuse_color;
	t_color			specular_color;

	light_tmp = (t_point_light *)world.point_lights->content;
	ambient_color = get_final_ambient_color(pcomp.object->material, light_tmp);
	light_dot_normal = compute_light_dot_normal(pcomp, light_tmp);
	pcomp.over_i = ft_add_tuples(pcomp.i, ft_scale_tuple(pcomp.normalv, ACNE_PRECISION));
	if (pcomp.object->material.texture_type == PATTERN_TEXTURE_TYPE)
		pcomp.object->material.color = checker_at_object(pcomp.object->material.pattern, *pcomp.object, pcomp.over_i);
	if (light_dot_normal < 0 || is_in_shadow(world, pcomp.over_i))
	{
		diffuse_color = create_color(0, 0, 0);
		specular_color = create_color(0, 0, 0);
	}
	else
	{
		diffuse_color = get_final_diffuse_color(pcomp.object->material, light_dot_normal, light_tmp);
		specular_color = get_final_specular_color(pcomp, light_tmp);
	}
	return (ft_add_colors(ft_add_colors(ambient_color, diffuse_color), specular_color));
}
