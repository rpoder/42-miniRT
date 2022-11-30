/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:54:59 by mpourrey          #+#    #+#             */
/*   Updated: 2022/11/30 14:26:14 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	new_cylinder->transform_m = translate_and_scale_object(values.origin,
			values.radius);
	new_cylinder->transform_m = orient_object(new_cylinder,
			values.orientation_vector);
	node = ft_lstnew(new_cylinder);
	if (!node)
	{
		free(new_cylinder);
		return (NULL);
	}
	ft_lstadd_back(&data->world->objects, node);
	return (new_cylinder);
}
