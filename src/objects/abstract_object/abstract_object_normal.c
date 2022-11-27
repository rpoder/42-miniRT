/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abstract_object_normal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:34:34 by ronanpoder        #+#    #+#             */
/*   Updated: 2022/11/27 23:24:20 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	get_object_normal_at(t_object *object, t_tuple world_point)
{
	t_tuple		object_normal;
	t_tuple		object_point;
	t_matrix4	inv_matrix;
	t_tuple		world_normal;
	t_matrix4	transposed_matrix;

	inv_matrix = ft_inverse_matrix(object->transform_m);
	object_point = multiply_matrix_by_tuple(inv_matrix, world_point);
	if (object->object_type == SPHERE_TYPE)
		object_normal = get_sphere_normal_at(object, object_point);
	else if (object->object_type == PLANE_TYPE)
		object_normal = get_plane_normal_at();
	else if (object->object_type == CUBE_TYPE)
		object_normal = get_cube_normal_at(object, object_point);
	else if (object->object_type == CYLINDER_TYPE)
		object_normal = get_cylinder_normal_at(object, object_point);
	else if (object->object_type == CONE_TYPE)
		object_normal = get_cone_normal_at(object, object_point);
	else if (object->object_type == TRIANGLE_TYPE)
		object_normal = get_triangle_normal_at(object, object_point);
	else
	{
		printf("ERR: undefined object type on normal_at().\n");
		exit(1);
	}
	transposed_matrix = ft_transpose_matrix(inv_matrix);
	world_normal = multiply_matrix_by_tuple(transposed_matrix, object_normal);
	world_normal.w = 0;
	world_normal = normalize_tuple(world_normal);
	return (world_normal);
}
