/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:37:48 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/27 13:11:28 by rpoder           ###   ########.fr       */
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
	t_ray		ray;
	t_tuple		new_position;
	t_object	*sphere;
	t_tuple		normal;
	t_tuple		point;
	t_matrix4	t1;
	t_matrix4	t2;

	ray.origin = ft_create_tuple(0.0, 0.0, -5.0, 1.0);

	point = ft_create_tuple(0.0, 0.70711, -0.70711, 1.0);
	sphere = ft_create_sphere(NULL, ft_create_tuple(0.0, 0.0, 0.0, 1.0), 1);
	t1 = ft_calculate_scaling_matrix(1.0, 0.5, 1.0);
	t2 = ft_calculate_rotation_z_matrix(M_PI/5.0);
	sphere->transform_m = ft_multiply_matrices(t2, t1);
	// sphere->transform_m = ft_calculate_translation_matrix(0, 1, 0);
	normal = sphere_normal_at(*sphere, point);
	ft_print_tuple("N", normal);


	/* DISPLAY */
	// t_intersections			sphere_intersects;
	// t_hit					hit;
	// int						win_x;
	// int						win_y;
	// float						ray_y;
	// float						ray_x;

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
	// 		// printf("ray_y = %f\n", ray_y);
	// 		ray.direction = ft_create_tuple(ray_x, ray_y, 5, 0);
	// 		// ft_print_tuple("ray.direction", ray.direction);
	// 		ray.direction = ft_normalize_tuple(ray.direction);
	// 		sphere_intersects = ft_get_sphere_intersections(sphere, ray);
	// 		hit = find_hit(sphere_intersects);
	// 		if (hit.does_hit == true)
	// 			my_mlx_pixel_put(&mlx_data.image, win_x, win_y, 0xff00ff00);
	// 		win_y++;
	// 	}
	// 	win_x++;
	// }

	mlx_put_image_to_window(mlx_data.mlx, mlx_data.win, mlx_data.image.img, 0, 0);
	mlx_loop(mlx_data.mlx);


}


