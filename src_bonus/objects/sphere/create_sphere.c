/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:00:07 by mpourrey          #+#    #+#             */
/*   Updated: 2022/11/30 22:11:06 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	*create_sphere(t_data *data, t_sphere_values_tool values)
{
	t_object	*new_sphere;
	t_list		*node;

	new_sphere = malloc(sizeof(t_object));
	if (!new_sphere)
		return (NULL);
	new_sphere->id = ft_lstlen(data->world->objects);
	new_sphere->object_type = SPHERE_TYPE;
	new_sphere->transform_m = translate_and_scale_object(values.origin,
			values.radius);
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
