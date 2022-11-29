/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:40:37 by mpourrey          #+#    #+#             */
/*   Updated: 2022/11/29 22:09:51 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_matrix4	orient_cone(t_object *cone, t_tuple orientation)
{
	float	radian_x;
	float	radian_y;
	float	radian_z;

	if (orientation.x > 0.0 + EPSILON || orientation.x < 0.0 - EPSILON)
	{
		radian_x = (orientation.x * 90) * M_PI / 180;
		cone->transform_m = multiply_matrices(cone->transform_m, compute_rotation_x_matrix(radian_x));
	}
	if (orientation.y > 0.0 + EPSILON || orientation.y < 0.0 - EPSILON)
	{
		radian_y = (orientation.x * 90) * M_PI / 180;
		cone->transform_m = multiply_matrices(cone->transform_m, compute_rotation_y_matrix(radian_y));
	}
		if (orientation.z > 0.0 + EPSILON || orientation.z < 0.0- EPSILON)
	{
		radian_z = (orientation.z * 90) * M_PI / 180;
		cone->transform_m = multiply_matrices(cone->transform_m, compute_rotation_z_matrix(radian_z));
	}
	return (cone->transform_m);
}

static t_matrix4	translate_and_scale_cone(t_tuple origin, double radius)
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

t_object	*create_cone(t_data *data, t_cone_values_tool values)
{
	t_object	*new_cone;
	t_list		*node;

	new_cone = malloc(sizeof(t_object));
	if (!new_cone)
		return (NULL);
	new_cone->id = ft_lstlen(data->world->objects);
	new_cone->object_type = CONE_TYPE;
	new_cone->material = get_default_material();
	new_cone->material.color = values.color;
	new_cone->min = -values.height / 2.0;
	new_cone->max = values.height / 2.0;
	new_cone->is_capped = true;
	new_cone->transform_m = translate_and_scale_cone(values.origin, values.radius);
	new_cone->transform_m = orient_cone(new_cone, values.orientation_vector);
	node = ft_lstnew(new_cone);
	if (!node)
	{
		free(new_cone);
		return (NULL);
	}
	ft_lstadd_back(&data->world->objects, node);
	return (new_cone);
}