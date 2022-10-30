/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:31:56 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/30 16:08:02 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_point_light	*create_point_light(t_data *data, t_color intensity, t_tuple pos)
{
	t_list			*node;
	t_point_light	*point_light;

	point_light = malloc(sizeof(point_light));
	if (!point_light)
		return (NULL);
	point_light->intensity = intensity;
	point_light->position = pos;
	node = ft_lstnew(point_light);
	if (!node)
	{
		free(point_light);
		return (NULL);
	}
	ft_lstadd_back(&data->point_lights, node);
	return (point_light);
}

static	t_tuple	ft_reflect_in(t_tuple in, t_tuple normal)
{
	return (ft_sub_tuples(in, ft_scale_tuple(normal, 2.0 * ft_tuple_scalarproduct(in, normal))));
}

t_color	get_lighted_color(t_material mat, t_point_light light, t_tuple point, t_tuple eyev, t_tuple normalv)
{
	t_color	effective_color;
	t_tuple	lightv;
	t_tuple	reflectv;
	double	light_dot_normal;
	double	reflect_dot_eye;
	t_color	ambient_color;
	t_color	diffuse_color;
	t_color	specular_color;
	double	factor;
	t_color	res;

	effective_color = ft_multiply_colors(mat.color, light.intensity);

	lightv = ft_normalize_tuple(ft_sub_tuples(light.position, point));

	ambient_color = ft_scale_color(effective_color, mat.ambient);

	light_dot_normal = ft_tuple_scalarproduct(lightv, normalv);

	if (light_dot_normal < 0)
	{
		diffuse_color = ft_create_color(0, 0, 0);
		specular_color = ft_create_color(0, 0, 0);
	}
	else
	{
		diffuse_color = ft_scale_color(ft_scale_color(effective_color, mat.diffuse), light_dot_normal);
		reflectv = ft_reflect_in(lightv, normalv);
		reflect_dot_eye = ft_tuple_scalarproduct(ft_neg_tuple(reflectv), eyev);
		if (reflect_dot_eye <= 0)
		{
			specular_color = ft_create_color(0, 0, 0);
		}
		else
		{
			factor = pow(reflect_dot_eye, mat.shininess);
			specular_color = ft_scale_color(ft_scale_color(light.intensity, mat.specular), factor);
		}
	}
	res = ft_add_colors(ft_add_colors(ambient_color, diffuse_color), specular_color);
	return (res);
}
