/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:01:36 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/28 17:39:22 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	*ft_create_sphere(t_data *data, t_tuple origin, int radius)
{
	t_object	*new_sphere;
	t_list		*node;
	t_material	mat;

	new_sphere = malloc(sizeof(t_object));
	if (!new_sphere)
		return (NULL);
	// new_sphere->id = ft_lstlen(data->objects);
	new_sphere->origin = origin;
	new_sphere->radius = radius;
	new_sphere->transform_m = ft_get_identity_matrix();
	mat.color = ft_create_color(1, 1, 1);
	mat.ambient = 0.1;
	mat.diffuse = 0.9;
	mat.specular = 1;
	mat.shininess = 200.0;
	new_sphere->material = mat;
	// node = ft_lstnew(new_sphere);
	// if (!node)
	// {
	// 	free(new_sphere);
	// 	return (NULL);
	// }
	// ft_lstadd_back(&data->objects, node);
	return (new_sphere);
}

t_tuple	sphere_normal_at(t_object sphere, t_tuple world_point)
{
	t_tuple	origin;
	t_tuple	object_point;
	t_tuple	world_normal;
	t_tuple	object_normal;
	t_matrix4	inv_matrix;
	t_matrix4	transposed_matrix;

	inv_matrix = ft_inverse_matrix(sphere.transform_m);
	object_point = ft_multiply_matrix_by_tuple(inv_matrix, world_point);
	origin = ft_create_tuple(0, 0, 0, 1);
	object_normal = ft_sub_tuples(object_point, origin);
	transposed_matrix = ft_transpose_matrix(inv_matrix);
	world_normal = ft_multiply_matrix_by_tuple(transposed_matrix, object_normal);
	world_normal.w = 0;
	world_normal = ft_normalize_tuple(world_normal);
	return (world_normal);
}
