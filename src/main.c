/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:37:48 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/30 13:05:05 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	handle_key_event(int keycode)
{
	if (keycode == 65307)
		exit(0);
	return (0);
}

int	main(void)
{

	// ft_convert_color_to_longint(ft_create_color(-0.3, 1, 1));

 	/* TIME */
	t_mlx_data	mlx_data;

	mlx_data.mlx = mlx_init();
 	mlx_data.win = mlx_new_window(mlx_data.mlx, 1000, 1000, "Hello world!");
	mlx_hook(mlx_data.win, 2, 1 << 0, handle_key_event, NULL);
	mlx_data.image.img = mlx_new_image(mlx_data.mlx, 1000, 1000);
	mlx_data.image.addr = mlx_get_data_addr(mlx_data.image.img,
		&mlx_data.image.bits_per_pixel, &mlx_data.image.line_length,
		&mlx_data.image.endian);

	/* TESTS */
	t_object		*sphere;
	t_tuple			normalv;
	t_tuple			eyev;
	t_point_light	light;
	t_color			res;
	t_matrix4		t1;
	t_matrix4		t2;
	t_ray			ray;

	sphere = ft_create_sphere(NULL, ft_create_tuple(0, 0, 0, 1), 1);

	// t1 = ft_calculate_scaling_matrix(1.2, 0.8, 0.8);
	// t2 = ft_calculate_shearing_matrix(shearing);
	// sphere->transform_m = ft_multiply_matrices(t2, t1);

	sphere->material.color = ft_create_color(1, 0, 1);

	light = ft_create_point_light(ft_create_color(1, 1, 1), ft_create_tuple(-10, 10, -10, 1));

	/* CAMERA */
	ray = ft_create_ray(ft_create_tuple(0, 0, -5, 1), ft_create_tuple(0, 0, 1, 0));

	/* DISPLAY */
	t_intersections			sphere_intersects;
	t_hit					hit;
	int						win_x;
	int						win_y;
	double					ray_y;
	double					ray_x;
	t_tuple					point;

	win_y = 0;
	win_x = 0;
	ray_y = 2;
	ray_x = -2;

	while (win_x < 1000)
	{
		ray_x = ray_x + (1.0 / 250.0);
		win_y = 0;
		ray_y = 2;
		while(win_y < 1000)
		{
			ray_y = ray_y - (1.0 / 250.0);
			ray.direction = ft_create_tuple(ray_x, ray_y, 5, 0);
			ray.direction = ft_normalize_tuple(ray.direction);
			sphere_intersects = ft_get_sphere_intersections(sphere, ray);

			hit = find_hit(sphere_intersects);
			if (hit.does_hit == true)
			{
				point = ft_calculate_new_point_on_ray(ray, hit.i);
				normalv = sphere_normal_at(*sphere, point);
				eyev = ft_neg_tuple(ray.direction);
				res = get_lighted_color(sphere->material, light, point, ft_normalize_tuple(eyev), ft_normalize_tuple(normalv));

				// my_mlx_pixel_put(&mlx_data.image, win_x, win_y, 0x00ffff00);
				my_mlx_pixel_put(&mlx_data.image, win_x, win_y, ft_convert_color_to_longint(res));

			}
			win_y++;
		}
		win_x++;
	}
	mlx_put_image_to_window(mlx_data.mlx, mlx_data.win, mlx_data.image.img, 0, 0);
	printf("------------------------------------------------------------------------IMAGE DISPLAYED\n");
	mlx_loop(mlx_data.mlx);

}


