/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:37:48 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/23 18:56:08 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(void)
{
	// t_mlx_data	mlx_data;

	// mlx_data.mlx = mlx_init();
	// mlx_data.win = mlx_new_window(mlx_data.mlx, 1920, 1080, "Hello world!");
	// mlx_data.image.img = mlx_new_image(mlx_data.mlx, 1920, 1080);
	// mlx_data.image.addr = mlx_get_data_addr(mlx_data.image.img,
	// 	&mlx_data.image.bits_per_pixel, &mlx_data.image.line_length,
	// 	&mlx_data.image.endian);


	t_ray					ray;
	t_tuple					new_position;
	t_sphere				sphere;
	t_intersections			sphere_intersects;
	t_hit					hit;

	ray.origin = ft_create_tuple(3, -1, -5, 1);
	ray.direction = ft_create_tuple(0, 0, 1, 0);
	sphere.radius = 1;
	sphere.origin = ft_create_tuple(0, 0, 0, 1);


	sphere_intersects = ft_get_sphere_intersections(sphere, ray);
	printf("i1 = %f | i2 = %f\n", sphere_intersects.i1, sphere_intersects.i2);

	hit = find_hit(sphere_intersects);
	printf("hit_bool = %d | hit i = %f", hit.does_hit, hit.i);
	// ft_print_tuple("new_position", new_position);
	// mlx_put_image_to_window(mlx_data.mlx, mlx_data.win, mlx_data.image.img, 0, 0);
	// mlx_loop(mlx_data.mlx);

	// printf("determinant = %f\n", ft_calculate_m3_determinant(m3_1));

}


