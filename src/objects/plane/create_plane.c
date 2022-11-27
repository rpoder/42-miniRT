/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:59:01 by mpourrey          #+#    #+#             */
/*   Updated: 2022/11/27 23:16:01 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_matrix4	orient_plane(t_object *plane, t_tuple orientation)
{
	float	radian_x;
	float	radian_y;
	float	radian_z;

	if (orientation.x > 0.0 + EPSILON || orientation.x < 0.0 - EPSILON)
	{
		radian_x = (orientation.x * 90) * M_PI / 180;
		plane->transform_m = multiply_matrices(plane->transform_m, compute_rotation_x_matrix(radian_x));
	}
	if (orientation.y > 0.0 + EPSILON || orientation.y < 0.0 - EPSILON)
	{
		radian_y = (orientation.x * 90) * M_PI / 180;
		plane->transform_m = multiply_matrices(plane->transform_m, compute_rotation_y_matrix(radian_y));
	}
		if (orientation.z > 0.0 + EPSILON || orientation.z < 0.0- EPSILON)
	{
		radian_z = (orientation.z * 90) * M_PI / 180;
		plane->transform_m = multiply_matrices(plane->transform_m, compute_rotation_z_matrix(radian_z));
	}
	return (plane->transform_m);
}

static t_matrix4 translate_plane(t_tuple origin)
{
	t_matrix4	transform_m;

	transform_m = get_identity_matrix();
	if (origin.x != 0.0 || origin.y != 0.0 || origin.x != 0.0)
		transform_m = compute_translation_matrix(origin.x, origin.y, origin.z);
	return (transform_m);
}

t_object	*create_plane(t_data *data, t_plane_values_tool values)
{
	t_object	*new_plane;
	t_list		*node;

	new_plane = malloc(sizeof(t_object));
	if (!new_plane)
		return (NULL);
	new_plane->id = ft_lstlen(data->world->objects);
	new_plane->object_type = PLANE_TYPE;
	new_plane->transform_m = translate_plane(values.origin);
	new_plane->transform_m = orient_plane(new_plane, values.orientation_vector);
	new_plane->material = get_default_material();
	new_plane->material.color = values.color;
	node = ft_lstnew(new_plane);
	if (!node)
	{
		free(new_plane);
		return (NULL);
	}
	ft_lstadd_back(&data->world->objects, node);
	return (new_plane);
}
