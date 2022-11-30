/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:25:26 by mpourrey          #+#    #+#             */
/*   Updated: 2022/11/30 16:33:47 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_ray	ray_for_pixel(t_camera *camera, double canvas_x,
		double canvas_y)
{
	t_offset	offset;
	double		world_x;
	double		world_y;
	t_tuple		pixel;
	t_ray		ray;

	ray = create_ray(create_tuple(0, 0, 0, 0), create_tuple(0, 0, 0, 0));
	offset.x = (canvas_x + 0.5) * camera->pixel_size;
	offset.y = (canvas_y + 0.5) * camera->pixel_size;
	world_x = camera->half_width - offset.x;
	world_y = camera->half_height - offset.y;
	pixel = multiply_matrix_by_tuple(ft_inverse_matrix(camera->transform_m),
			create_tuple(world_x, world_y, -1, 1));
	ray.origin = multiply_matrix_by_tuple(ft_inverse_matrix(
				camera->transform_m), create_tuple(0, 0, 0, 1));
	ray.direction = normalize_tuple(sub_tuples(pixel, ray.origin));
	return (ray);
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
			ray = ray_for_pixel(camera, x, y);
			color = get_color_on_ray(*world, ray);
			my_mlx_pixel_put(&data->mlx_data->image, x, y,
				ft_convert_color_to_longint(color));
			x++;
		}
		y++;
	}
}
