/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margot <margot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:01:36 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/03 16:55:03 by margot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	*create_sphere(t_data *data, t_tuple origin, int radius)
{
	t_object	*new_sphere;
	t_list		*node;

	new_sphere = malloc(sizeof(t_object));
	if (!new_sphere)
		return (NULL);
	new_sphere->id = ft_lstlen(data->world->objects);
	new_sphere->transform_m = compute_parsing_sphere_transform_m(origin, radius);
	new_sphere->material = get_default_material();
	node = ft_lstnew(new_sphere);
	if (!node)
	{
		free(new_sphere);
		return (NULL);
	}
	ft_lstadd_back(&data->world->objects, node);
	return (new_sphere);
}

static t_matrix4	compute_parsing_sphere_transform_m(t_tuple origin, int radius)
{
	t_matrix4	t1;
	t_matrix4	t2;
	t_matrix4	transform_matrix;

	t1 = get_identity_matrix();
	if (origin.x != 0 || origin.y != 0 || origin.x != 0)
		t1 = compute_translation_matrix(origin.x, origin.y, origin.z);
	t2 = compute_scaling_matrix(radius, radius, radius);
	transform_matrix = ft_multiply_matrices(t1, t2);
	return (transform_matrix);
}

t_tuple	sphere_normal_at(t_object *sphere, t_tuple world_point)
{
	t_tuple	origin;
	t_tuple	object_point;
	t_tuple	world_normal;
	t_tuple	object_normal;
	t_matrix4	inv_matrix;
	t_matrix4	transposed_matrix;

	inv_matrix = ft_inverse_matrix(sphere->transform_m);
	object_point = ft_multiply_matrix_by_tuple(inv_matrix, world_point);
	origin = create_tuple(0, 0, 0, 1);
	object_normal = ft_sub_tuples(object_point, origin);
	transposed_matrix = ft_transpose_matrix(inv_matrix);
	world_normal = ft_multiply_matrix_by_tuple(transposed_matrix, object_normal);
	world_normal.w = 0;
	world_normal = ft_normalize_tuple(world_normal);
	return (world_normal);
}
