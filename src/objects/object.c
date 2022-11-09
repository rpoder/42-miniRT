/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ronanpoder <ronanpoder@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:34:34 by ronanpoder        #+#    #+#             */
/*   Updated: 2022/11/09 16:40:10 by ronanpoder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_transform(t_object *obj, t_matrix4 transform_to_apply)
{
	if (obj)
	{
		obj->transform_m = ft_multiply_matrices(obj->transform_m,
			transform_to_apply);
	}
}

t_tuple	normal_at(t_object *object, t_tuple world_point)
{
	t_tuple		object_normal;
	t_tuple		object_point;
	t_matrix4	inv_matrix;
	t_tuple		world_normal;
	t_matrix4	transposed_matrix;

	// ft_print_matrix4(object->transform_m);
	inv_matrix = ft_inverse_matrix(object->transform_m);
	object_point = ft_multiply_matrix_by_tuple(inv_matrix, world_point);
	if (object->object_type == SPHERE_TYPE)
		object_normal = sphere_normal_at(object, object_point);
	else if (object->object_type == PLANE_TYPE)
		object_normal = plane_normal_at();
	else
	{
		printf("ERR: undefined object type on normal_at().\n");
		exit(1);
	}
	transposed_matrix = ft_transpose_matrix(inv_matrix);
	world_normal = ft_multiply_matrix_by_tuple(transposed_matrix, object_normal);
	world_normal.w = 0;
	world_normal = ft_normalize_tuple(world_normal);
	return (world_normal);
}
