/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_abstract_object.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 00:53:25 by mpourrey          #+#    #+#             */
/*   Updated: 2022/12/02 19:56:49 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	compute_angle(t_tuple a, t_tuple b)
{
	double	dot;
	double	tmp;
	double	angle;

	dot = dot_product(a, b);
	tmp = dot / tuple_len(a);
	angle = tmp / tuple_len(b);
	return (acosf(angle));
}

bool	tuple_value_is_zero(t_tuple	tuple)
{
	if ((tuple.x > -EPSILON && tuple.x < EPSILON)
		&& (tuple.y > -EPSILON && tuple.y < EPSILON)
		&& (tuple.z > -EPSILON && tuple.z < EPSILON))
		return (true);
	return (false);
}

t_matrix4	compute_rotation_m(t_object *object, t_tuple orient_v)
{
	double		z_angle;
	double		x_angle;
	double		xy_len;
	double		orientv_len;
	t_matrix4	transform_m;

	orient_v = normalize_tuple(orient_v);
	xy_len = sqrtf(orient_v.x * orient_v.x + orient_v.y * orient_v.y);
	if (xy_len == 0)
		z_angle = M_PI / 2;
	else
		z_angle = acosf(orient_v.y / xy_len);
	orientv_len = tuple_len(orient_v);
	x_angle = acosf(xy_len / orientv_len);
	if (xy_len / orientv_len >= 1 - EPSILON)
		x_angle = 0;
	if (orient_v.x > 0)
		z_angle = -z_angle;
	if (orient_v.z < 0)
		x_angle = -x_angle;
	transform_m = multiply_matrices(object->transform_m,
			compute_rotation_z_matrix(z_angle));
	transform_m = multiply_matrices(transform_m,
			compute_rotation_x_matrix(x_angle));
	return (transform_m);
}

t_matrix4	orient_object(t_object *object, t_tuple orientation)
{
	if (tuple_value_is_zero(orientation))
		return (object->transform_m);
	object->transform_m = multiply_matrices(object->transform_m,
			compute_rotation_m(object, orientation));
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
