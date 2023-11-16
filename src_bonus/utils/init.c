/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:14:24 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/30 22:13:28 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		global_free(NULL, MALLOC_ERR);
	data->mlx_data = NULL;
	data->world = malloc(sizeof(t_world));
	if (!data->world)
		global_free(data, MALLOC_ERR);
	data->world->objects = NULL;
	data->world->point_lights = NULL;
	data->world->camera = NULL;
	data->world->ambient_light = create_color(0, 0, 0);
	return (data);
}
