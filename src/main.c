/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:37:48 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/30 20:32:24 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(void)
{
	t_data	*data;

	data = init_data();
	data->mlx_data = start_mlx();

	/* TESTS */
	t_object		*sphere;
	t_object		*sphere2;
	t_tuple			normalv;
	t_tuple			eyev;
	t_point_light	*light;
	t_color			res;
	t_ray			ray;
	t_w_intersections	w_intersections;
	t_ray_precompute_tool	tool;

	light = create_point_light(data, ft_create_color(1, 1, 1), ft_create_tuple(-10, 10, -10, 1));
	sphere = create_sphere(data, ft_create_tuple(0, 0, 0, 1), 1);
	// sphere2 = create_sphere(data, ft_create_tuple(0, 0, 0, 1), 1);
	// sphere2->transform_m = ft_multiply_matrices(sphere2->transform_m, compute_scaling_matrix(0.5, 0.5, 0.5));
	// t1 = compute_scaling_matrix(1.2, 0.8, 0.8);
	// t2 = compute_shearing_matrix(shearing);
	// sphere->transform_m = ft_multiply_matrices(t2, t1);

	sphere->material.color = ft_create_color(1, 0, 1);


	/* CAMERA */
	ray = ft_create_ray(ft_create_tuple(0, 0, 0, 1), ft_create_tuple(0, 0, 1, 0));

	w_intersections = compute_world_intersections(data, ray);


	tool = precompute_ray(w_intersections, ray);















	// /* DISPLAY */
	// t_intersections			sphere_intersects;
	// t_hit					hit;
	// int						win_x;
	// int						win_y;
	// double					ray_y;
	// double					ray_x;
	// t_tuple					point;
	// // double					intersections[100];

	// win_y = 0;
	// win_x = 0;
	// ray_y = 2;
	// ray_x = -2;

	// while (win_x < 1000)
	// {
	// 	ray_x = ray_x + (1.0 / 250.0);
	// 	win_y = 0;
	// 	ray_y = 2;
	// 	while(win_y < 1000)
	// 	{
	// 		ray_y = ray_y - (1.0 / 250.0);
	// 		ray.direction = ft_create_tuple(ray_x, ray_y, 5, 0);
	// 		ray.direction = ft_normalize_tuple(ray.direction);
	// 		sphere_intersects = get_sphere_intersections(sphere, ray);

	// 		hit = find_hit(sphere_intersects);
	// 		if (hit.does_hit == true)
	// 		{
	// 			point = compute_new_point_on_ray(ray, hit.i);
	// 			normalv = sphere_normal_at(*sphere, point);
	// 			eyev = ft_neg_tuple(ray.direction);
	// 			res = get_lighted_color(sphere->material, *light, point, ft_normalize_tuple(eyev), ft_normalize_tuple(normalv));

	// 			// my_mlx_pixel_put(&data->mlx_data->image, win_x, win_y, 0x00ffff00);
	// 			my_mlx_pixel_put(&data->mlx_data->image, win_x, win_y, ft_convert_color_to_longint(res));

	// 		}
	// 		win_y++;
	// 	}
	// 	win_x++;
	// }
	// mlx_put_image_to_window(data->mlx_data->mlx, data->mlx_data->win, data->mlx_data->image.img, 0, 0);
	// printf("------------------------------------------------------------------------IMAGE DISPLAYED\n");
	// mlx_loop(data->mlx_data->mlx);

}


