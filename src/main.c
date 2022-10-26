/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:37:48 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/26 11:40:07 by mpourrey         ###   ########.fr       */
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

	t_mlx_data	mlx_data;

	mlx_data.mlx = mlx_init();
 	mlx_data.win = mlx_new_window(mlx_data.mlx, 1000, 1000, "Hello world!");
	mlx_hook(mlx_data.win, 2, 1 << 0, handle_key_event, NULL);
	mlx_data.image.img = mlx_new_image(mlx_data.mlx, 1000, 1000);
	mlx_data.image.addr = mlx_get_data_addr(mlx_data.image.img,
		&mlx_data.image.bits_per_pixel, &mlx_data.image.line_length,
		&mlx_data.image.endian);


	t_ray					ray;
	t_tuple					new_position;
	t_object				*sphere;
	t_intersections			sphere_intersects;
	t_hit					hit;

	ray.origin = ft_create_tuple(0, 0, -5, 1);
	ray.direction = ft_create_tuple(0, 0, 1, 0);
	printf("\n");
	ft_print_tuple("ray.direction", ray.direction);
	printf("\n");
	ray.direction = ft_normalize_tuple(ray.direction);
	sphere = ft_create_sphere(NULL, ft_create_tuple(0, 0, 0, 1), 1);
	sphere->transform_m = ft_calculate_translation_matrix(0, 0, 1);
	sphere_intersects = ft_get_sphere_intersections(sphere, ray);
	t_hit = find_hit(sphere_intersects);
	printf("i1 %f | i2 %f\n", sphere_intersects.i1, sphere_intersects.i2); 


	while(i < 1000)
	{
		
	}

	mlx_put_image_to_window(mlx_data.mlx, mlx_data.win, mlx_data.image.img, 0, 0);
	mlx_loop(mlx_data.mlx);


}


