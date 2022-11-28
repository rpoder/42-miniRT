/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:14:24 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/28 11:48:11 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->mlx_data = NULL;
	data->world = malloc(sizeof(t_world));
	if (!data->world)
	{
		free(data);
		return (NULL);
	}
	data->world->objects = NULL;
	data->world->point_lights = NULL;
	data->world->camera = NULL;
	data->world->ambient_light = create_color(0, 0, 0);
	return (data);
}
