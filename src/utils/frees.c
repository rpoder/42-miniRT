/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:49:24 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/28 16:06:46 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	global_free(t_data *data, int error)
{
	if (data)
	{
		if (data->mlx_data)
		{
			if (data->mlx_data->image.img)
				mlx_destroy_image(data->mlx_data->mlx, data->mlx_data->image.img);
			if (data->mlx_data->win)
				mlx_destroy_window(data->mlx_data->mlx, data->mlx_data->win);
			if (data->mlx_data->mlx)
			{
				mlx_destroy_display(data->mlx_data->mlx);
				free(data->mlx_data->mlx);
			}
			free(data->mlx_data);
		}
		if (data->world)
		{
			if (data->world->objects)
				ft_lstclear(&data->world->objects, free);
			if (data->world->point_lights)
				ft_lstclear(&data->world->point_lights, free);
			if (data->world->camera)
				free(data->world->camera);
			free(data->world);
		}
		free(data);
	}
	exit (error);
}
