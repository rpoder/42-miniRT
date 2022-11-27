/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:54:59 by mpourrey          #+#    #+#             */
/*   Updated: 2022/11/27 23:16:01 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_matrix4	orient_cylinder(t_object *cylinder, t_tuple orientation)
{
	float	radian_x;
	float	radian_y;
	float	radian_z;

	if (orientation.x > 0.0 + EPSILON || orientation.x < 0.0 - EPSILON)
	{
		radian_x = (orientation.x * 90) * M_PI / 180;
		cylinder->transform_m = multiply_matrices(cylinder->transform_m, compute_rotation_x_matrix(radian_x));
	}
	if (orientation.y > 0.0 + EPSILON || orientation.y < 0.0 - EPSILON)
	{
		radian_y = (orientation.x * 90) * M_PI / 180;
		cylinder->transform_m = multiply_matrices(cylinder->transform_m, compute_rotation_y_matrix(radian_y));
	}
		if (orientation.z > 0.0 + EPSILON || orientation.z < 0.0- EPSILON)
	{
		radian_z = (orientation.z * 90) * M_PI / 180;
		cylinder->transform_m = multiply_matrices(cylinder->transform_m, compute_rotation_z_matrix(radian_z));
	}
	return (cylinder->transform_m);
}

static t_matrix4	translate_and_scale_cylinder(t_tuple origin, double radius)
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

t_object	*create_cylinder(t_data *data, t_cylinder_values_tool values)
{
	t_object	*new_cylinder;
	t_list		*node;

	new_cylinder = malloc(sizeof(t_object));
	if (!new_cylinder)
		return (NULL);
	new_cylinder->id = ft_lstlen(data->world->objects);
	new_cylinder->object_type = CYLINDER_TYPE;
	new_cylinder->material = get_default_material();
	new_cylinder->material.color = values.color;
	new_cylinder->min = -values.height / 2.0;
	new_cylinder->max = values.height / 2.0;
	new_cylinder->is_capped = true;
	new_cylinder->transform_m = translate_and_scale_cylinder(values.origin, values.radius);
	new_cylinder->transform_m = orient_cylinder(new_cylinder, values.orientation_vector);

//	new_cylinder->transform_m = compute_parsing_cylinder_transform_m(values.origin, values.radius);
//	transform_cylinder_orientation(new_cylinder, values.orientation_vector);
	node = ft_lstnew(new_cylinder);
	if (!node)
	{
		free(new_cylinder);
		return (NULL);
	}
	ft_lstadd_back(&data->world->objects, node);
	return (new_cylinder);
}
