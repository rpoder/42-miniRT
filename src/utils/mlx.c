/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:01:33 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/28 13:21:22 by rpoder           ###   ########.fr       */
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

void	start_mlx(t_data *data)
{
	data->mlx_data = malloc(sizeof(t_mlx_data));
	if (!data->mlx_data)
		global_free(data, MLX_ERR);
	data->mlx_data->image.img = NULL;
	data->mlx_data->win = NULL;
	data->mlx_data->mlx = NULL;
	data->mlx_data->mlx = mlx_init();
	if (!data->mlx_data->mlx)
		global_free(data, MLX_ERR);
 	data->mlx_data->win = mlx_new_window(data->mlx_data->mlx, CANVAS_X, CANVAS_Y, "Hello Zobi !");
	if (!data->mlx_data->win)
		global_free(data, MLX_ERR);
	data->mlx_data->image.img = mlx_new_image(data->mlx_data->mlx, CANVAS_X, CANVAS_Y);
	if (!data->mlx_data->image.img)
		global_free(data, MLX_ERR);
	data->mlx_data->image.addr = mlx_get_data_addr(data->mlx_data->image.img,
		&data->mlx_data->image.bits_per_pixel, &data->mlx_data->image.line_length,
		&data->mlx_data->image.endian);
	if (!data->mlx_data->image.addr)
		global_free(data, MLX_ERR);
	mlx_hook(data->mlx_data->win, 17, 0L, handle_mouse_event, data);
	mlx_hook(data->mlx_data->win, 2, 1 << 0, handle_key_event, NULL);
}
