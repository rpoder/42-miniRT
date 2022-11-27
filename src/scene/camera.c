/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:15:58 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/27 19:50:31 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
			// if (x == 433 && y == 195)
			// {
				ray = ray_for_pixel(camera, x, y);
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

double	compute_pixel_size(t_camera *camera, int hsize, int vsize, double fov)
{
	double		half_fov;
	double		aspect;

	half_fov = tan(fov / 2.0);
	aspect = (double)hsize / (double)vsize;
	if (aspect >= 1)
	{
		camera->half_width = half_fov;
		camera->half_height = half_fov / aspect;
	}
	else
	{
		camera->half_width = half_fov * aspect;
		camera->half_height = half_fov;
	}
	return ((camera->half_width * 2) / (double)hsize);
}

// t_camera	*create_camera(t_data *data, int hsize, int vsize, double fov)
// {
// 	data->world->camera = malloc(sizeof(t_camera));
// 	if (!data->world->camera)
// 		return (NULL);
// 	data->world->camera->vsize = vsize;
// 	data->world->camera->hsize = hsize;
// 	data->world->camera->fov = fov;
// 	data->world->camera->transform_m = get_identity_matrix();
// 	data->world->camera->pixel_size = compute_pixel_size(data->world->camera, hsize, vsize, fov);
// 	return (data->world->camera);
// }

t_camera	*create_camera(t_data *data, int hsize, int vsize, t_camera_values_tool values)
{
	t_tuple	to;
	t_tuple	tmp;
	t_tuple	up;

	data->world->camera = malloc(sizeof(t_camera));
	if (!data->world->camera)
		return (NULL);
	data->world->camera->vsize = vsize;
	data->world->camera->hsize = hsize;
	data->world->camera->fov = values.fov;
	data->world->camera->pixel_size = compute_pixel_size(data->world->camera, hsize, vsize, values.fov);
	to = ft_add_tuples(values.origin, values.orientation_vector);
	print_tuple("to", to);
	if (to.x == 0.0)
		to.x = EPSILON;
	// if (to.z == 0.0)
	// 	to.z == EPSILON;
	tmp = ft_multiply_tuples(create_tuple(0, 1, 0, 0), ft_normalize_tuple(to));

	////////
	// tmp = ft_neg_tuple(tmp);

	if (ft_tuple_scalarproduct(create_tuple(0, 0, 1, 0), ft_normalize_tuple(values.orientation_vector)) >= 0.0)
		tmp = ft_neg_tuple(tmp);
	up = ft_normalize_tuple(ft_multiply_tuples(values.orientation_vector, tmp));
	// if (up.x == 1.0 && up.y == 0 && up.z == 0)
	// 	up = create_tuple(0, 0, 1, 0);
	print_tuple("up", up);
	data->world->camera->transform_m = compute_view_transform_m(values.origin, to, up);
	return (data->world->camera);
}

t_ray	ray_for_pixel(t_camera *camera, double canvas_x, double canvas_y)
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
