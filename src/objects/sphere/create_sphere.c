/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:00:07 by mpourrey          #+#    #+#             */
/*   Updated: 2022/11/27 23:16:01 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_matrix4	translate_and_scale_sphere(t_tuple origin, double radius)
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

t_object	*create_sphere(t_data *data, t_sphere_values_tool values)
{
	t_object	*new_sphere;
	t_list		*node;

	new_sphere = malloc(sizeof(t_object));
	if (!new_sphere)
		return (NULL);
	new_sphere->id = ft_lstlen(data->world->objects);
	new_sphere->object_type = SPHERE_TYPE;
	new_sphere->transform_m = translate_and_scale_sphere(values.origin, values.radius);
	new_sphere->material = get_default_material();
	new_sphere->material.color = values.color;
	node = ft_lstnew(new_sphere);
	if (!node)
	{
		free(new_sphere);
		return (NULL);
	}
	ft_lstadd_back(&data->world->objects, node);
	return (new_sphere);
}
