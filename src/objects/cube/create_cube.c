/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cube.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:40:19 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/30 14:23:37 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	*create_cube(t_data *data, t_cube_values_tool values)
{
	t_object	*new_cube;
	t_list		*node;

	new_cube = malloc(sizeof(t_object));
	if (!new_cube)
		return (NULL);
	new_cube->id = ft_lstlen(data->world->objects);
	new_cube->object_type = CUBE_TYPE;
	new_cube->material = get_default_material();
	new_cube->material.color = values.color;
	new_cube->transform_m = multiply_matrices(get_identity_matrix(),
			compute_translation_matrix(values.origin.x,
				values.origin.y, values.origin.z));
	new_cube->transform_m = multiply_matrices(new_cube->transform_m,
			compute_scaling_matrix(values.radius,
				values.radius, values.radius));
	node = ft_lstnew(new_cube);
	if (!node)
	{
		free(new_cube);
		return (NULL);
	}
	ft_lstadd_back(&data->world->objects, node);
	return (new_cube);
}
