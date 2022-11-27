/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_lights.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:31:56 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/28 00:12:03 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_point_light	*create_point_light(t_data *data, t_color intensity, t_tuple pos)
{
	t_list			*node;
	t_point_light	*point_light;

	point_light = malloc(sizeof(t_point_light));
	if (!point_light)
		return (NULL);
	point_light->intensity = intensity;
	point_light->position = pos;
	node = ft_lstnew(point_light);
	if (!node)
	{
		free(point_light);
		return (NULL);
	}
	ft_lstadd_back(&data->world->point_lights, node);
	return (point_light);
}

t_tuple	ft_reflect_in(t_tuple in, t_tuple normal)
{
	return (sub_tuples(in, ft_scale_tuple(normal, 2.0 * dot_product(in, normal))));
}
