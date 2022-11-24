/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:37:48 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/24 15:20:58 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{

	t_data	*data;
	t_tuple	from;
	t_tuple	to;
	t_tuple	up;
 	t_object			*s1;
	t_object			*s2;
	t_object			*c1;
	t_object			*p1;
	t_point_light		*light;

	t_tuple				parsing_origin;
	t_tuple				parsing_orientation;
	t_ray				parsing_ray;

	data = init_data();

	data->mlx_data = start_mlx();

	create_camera(data, CANVAS_X, CANVAS_Y, M_PI/2);
	// from = create_tuple(0, 5, -5, 1);
	parsing_origin = create_tuple(0, 2, -10, 1);
	parsing_orientation = create_tuple(20, -0.5, 0.01, 0);

	parsing_ray.origin = parsing_origin;
	parsing_ray.direction = parsing_orientation;

	to = compute_new_point_on_normalized_ray(parsing_ray, 1.0);
	ft_print_tuple("to", to);
	up = create_tuple(0, 1, 0, 0);
	data->world->camera->transform_m = compute_view_transform_m(parsing_origin, to, up);
	data->world->view_transform_m = compute_view_transform_m(parsing_origin, to, up);

	light = create_point_light(data, create_color(1, 1, 1), create_tuple(10, 5, -10, 1));

	c1 = create_cube(data);
	// c1->transform_m = ft_multiply_matrices(c1->transform_m, compute_rotation_y_matrix(M_PI/4));
	c1->material.color = create_color(1, 0, 1);
	// c1->transform_m = ft_multiply_matrices(c1->transform_m, compute_translation_matrix(-10, 1, 0));

	render(data, data->world->camera, data->world);

	mlx_put_image_to_window(data->mlx_data->mlx, data->mlx_data->win,
		data->mlx_data->image.img, 0, 0);
	printf("IMAGE DISPLAYED ------------------------------------------------------------------------------------\n");
	mlx_loop(data->mlx_data->mlx);

	return (0);
}
