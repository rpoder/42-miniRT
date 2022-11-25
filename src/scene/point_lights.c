/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_lights.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:31:56 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/25 15:56:07 by mpourrey         ###   ########.fr       */
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

