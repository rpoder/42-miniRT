/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_abstract_object.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 00:53:25 by mpourrey          #+#    #+#             */
/*   Updated: 2022/11/30 01:08:13 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix4	orient_object(t_object *object, t_tuple orientation)
{
	float	radian_x;
	float	radian_y;
	float	radian_z;

	if (orientation.x > 0.0 + EPSILON || orientation.x < 0.0 - EPSILON)
	{
		radian_x = (orientation.x * 90) * M_PI / 180;
		object->transform_m = multiply_matrices(object->transform_m,
				compute_rotation_x_matrix(radian_x));
	}
	if (orientation.y > 0.0 + EPSILON || orientation.y < 0.0 - EPSILON)
	{
		radian_y = (orientation.x * 90) * M_PI / 180;
		object->transform_m = multiply_matrices(object->transform_m,
				compute_rotation_y_matrix(radian_y));
	}
	if (orientation.z > 0.0 + EPSILON || orientation.z < 0.0- EPSILON)
	{
		radian_z = (orientation.z * 90) * M_PI / 180;
		object->transform_m = multiply_matrices(object->transform_m,
				compute_rotation_z_matrix(radian_z));
	}
	return (object->transform_m);
}

t_matrix4	translate_and_scale_object(t_tuple origin, double radius)
{
	t_matrix4	t1;
	t_matrix4	t2;
	t_matrix4	transform_matrix;

	t1 = multiply_matrices(get_identity_matrix(),
			compute_translation_matrix(origin.x, origin.y, origin.z));
	t2 = compute_scaling_matrix(radius, radius, radius);
	transform_matrix = multiply_matrices(t1, t2);
	return (transform_matrix);
}
