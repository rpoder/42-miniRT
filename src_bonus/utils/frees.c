/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:49:24 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/30 22:08:09 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	free_world_datas(t_world *world)
{
	if (world->objects)
		ft_lstclear(&world->objects, free);
	if (world->point_lights)
		ft_lstclear(&world->point_lights, free);
	if (world->camera)
		free(world->camera);
}

static void	free_mlx_datas(t_mlx_data *mlx_data)
{
	if (mlx_data->image.img)
		mlx_destroy_image(mlx_data->mlx, mlx_data->image.img);
	if (mlx_data->win)
		mlx_destroy_window(mlx_data->mlx, mlx_data->win);
	if (mlx_data->mlx)
	{
		mlx_destroy_display(mlx_data->mlx);
		free(mlx_data->mlx);
	}
}

void	global_free(t_data *data, int error)
{
	if (error == MALLOC_ERR)
		ft_putstr_fd("ERR: crash on memory allocation.\n", 2);
	if (data)
	{
		if (data->mlx_data)
		{
			free_mlx_datas(data->mlx_data);
			free(data->mlx_data);
		}
		if (data->world)
		{
			free_world_datas(data->world);
			free(data->world);
		}
		free(data);
	}
	exit (error);
}
