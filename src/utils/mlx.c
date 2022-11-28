/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:01:33 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/28 13:02:22 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	handle_key_event(int keycode)
{
	if (keycode == 65307)
		exit(0);
	return (0);
}

static int	handle_mouse_event(t_data *data)
{
	global_free(data, NO_ERR);
	return (0);
}

void	my_mlx_pixel_put(t_image *image, int x, int y, long color)
{
	char	*dst;

	dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static t_mlx_data	*init_image(t_mlx_data *mlx_data)
{
	mlx_data->image.img = mlx_new_image(mlx_data->mlx, CANVAS_X, CANVAS_Y);
	if (!mlx_data->image.img)
	{
		mlx_destroy_window(mlx_data->mlx, mlx_data->win);
		mlx_destroy_display(mlx_data->mlx);
		free(mlx_data->mlx);
		free(mlx_data);
		return (NULL);
	}
	mlx_data->image.addr = mlx_get_data_addr(mlx_data->image.img,
		&mlx_data->image.bits_per_pixel, &mlx_data->image.line_length,
		&mlx_data->image.endian);
	if (!mlx_data->image.addr)
	{
		mlx_destroy_image(mlx_data->mlx, mlx_data->image.img);
		mlx_destroy_window(mlx_data->mlx, mlx_data->win);
		mlx_destroy_display(mlx_data->mlx);
		free(mlx_data->mlx);
		free(mlx_data);
		return (NULL);
	}
	return (mlx_data);
}

t_mlx_data	*start_mlx(t_data *data)
{
	t_mlx_data	*mlx_data;

	mlx_data = malloc(sizeof(t_mlx_data));
	if (!mlx_data)
		return (NULL);
	mlx_data->mlx = mlx_init();
	if (!mlx_data->mlx)
	{
		free(mlx_data);
		return (NULL);
	}
 	mlx_data->win = mlx_new_window(mlx_data->mlx, CANVAS_X, CANVAS_Y, "Hello Zobi !");
	if (!mlx_data->win)
	{
		mlx_destroy_display(mlx_data->mlx);
		free(mlx_data->mlx);
		free(mlx_data);
		return (NULL);
	}
	mlx_data = init_image(mlx_data);
	if (!mlx_data)
		return (NULL);
	mlx_hook(mlx_data->win, 17, 0L, handle_mouse_event, data);
	mlx_hook(mlx_data->win, 2, 1 << 0, handle_key_event, NULL);
	return (mlx_data);
}
