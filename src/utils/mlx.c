/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:01:33 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/30 15:59:00 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	handle_key_event(int keycode)
{
	if (keycode == 65307)
		exit(0);
	return (0);
}

void	my_mlx_pixel_put(t_image *image, int x, int y, long color)
{
	char	*dst;

	dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

t_mlx_data	*start_mlx(void)
{
	t_mlx_data	*mlx_data;

	mlx_data = malloc(sizeof(t_mlx_data));
	if (!mlx_data)
		return (NULL);
	mlx_data->mlx = mlx_init();
 	mlx_data->win = mlx_new_window(mlx_data->mlx, 1000, 1000, "Hello Bouboule!");
	mlx_hook(mlx_data->win, 2, 1 << 0, handle_key_event, NULL);
	mlx_data->image.img = mlx_new_image(mlx_data->mlx, 1000, 1000);
	mlx_data->image.addr = mlx_get_data_addr(mlx_data->image.img,
		&mlx_data->image.bits_per_pixel, &mlx_data->image.line_length,
		&mlx_data->image.endian);
	return (mlx_data);
}
