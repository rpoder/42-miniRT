/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:49:24 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/28 12:25:20 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	global_free(t_data *data, int error)
{
	if (data)
	{
		if (data->mlx_data)
		{
			mlx_destroy_image(data->mlx_data->mlx, data->mlx_data->image.img);
			mlx_destroy_window(data->mlx_data->mlx, data->mlx_data->win);
			mlx_destroy_display(data->mlx_data->mlx);
			free(data->mlx_data);
		}
		if (data->world)
		{
			free(data->world);
		}
		free(data);
	}
	exit (error);
}
