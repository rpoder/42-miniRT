/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_lighted_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:09:32 by margot            #+#    #+#             */
/*   Updated: 2022/11/07 17:32:15 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_color	get_final_specular_color(t_pcomp_tool pcomp, t_point_light *light)
{
	t_color	specular_color;
	t_tuple	lightv;
	t_tuple	reflectv;
	double	reflect_dot_eye;
	double	factor;

	lightv = ft_normalize_tuple(ft_sub_tuples(light->position, pcomp.i));
	reflectv = ft_reflect_in(ft_neg_tuple(lightv), pcomp.normalv);
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
	if (light_dot_normal < 0)
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
