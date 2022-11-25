/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:15:58 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/25 15:51:37 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_ray	compute_ray_for_pixel(t_camera *camera, double canvas_x, double canvas_y)
{
	t_offset	offset;
	double		world_x;
	double		world_y;
	t_tuple		pixel;
	t_tuple		origin;
	t_tuple		direction;

	offset.x = (canvas_x + 0.5) * camera->pixel_size;
	offset.y = (canvas_y + 0.5) * camera->pixel_size;

	world_x = camera->half_width - offset.x;
	world_y = camera->half_height - offset.y;

	pixel = ft_multiply_matrix_by_tuple(ft_inverse_matrix(camera->transform_m), create_tuple(world_x, world_y, -1, 1));
	origin = ft_multiply_matrix_by_tuple(ft_inverse_matrix(camera->transform_m), create_tuple(0, 0, 0, 1));
	direction = ft_normalize_tuple(ft_sub_tuples(pixel, origin));
	return (ft_create_ray(origin, direction));
}

void	render(t_data *data, t_camera *camera, t_world *world)
{
	int		x;
	int		y;
	t_ray	ray;
	t_color	color;

	y = 0;
	while (y < camera->vsize)
	{
		x = 0;
		while (x < camera->hsize)
		{
			// if (x == 340 && y == 120)
			// {
				ray = compute_ray_for_pixel(camera, x, y);
				color = get_color_on_ray(*world, ray);
				my_mlx_pixel_put(&data->mlx_data->image, x, y, ft_convert_color_to_longint(color));
			// }

			x++;
		}
		y++;
	}
	// mlx_put_image_to_window(data->mlx_data->mlx, data->mlx_data->win,
	// 	data->mlx_data->image.img, 0, 0);
}
