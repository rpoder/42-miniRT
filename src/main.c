/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:37:48 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/22 17:49:52 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"



int	main(void)
{
	t_mlx_data	mlx_data;

	mlx_data.mlx = mlx_init();
	mlx_data.win = mlx_new_window(mlx_data.mlx, 1920, 1080, "Hello world!");
	mlx_data.image.img = mlx_new_image(mlx_data.mlx, 1920, 1080);
	mlx_data.image.addr = mlx_get_data_addr(mlx_data.image.img,
		&mlx_data.image.bits_per_pixel, &mlx_data.image.line_length,
		&mlx_data.image.endian);


	t_tuple				point;
	t_matrix4			transform;
	t_matrix4			inv;
	t_tuple				new_point;
	int					offset_x;
	int					offset_y;
	int					i;

	point = ft_create_tuple(0, 100, 0, 1);
	transform = ft_get_rotate_z_matrix(M_PI / 1200);
	inv = ft_inverse_matrix(transform);
	new_point = point;
	offset_x = 300;
	offset_y = 300;
	while (i < 2400)
	{
		my_mlx_pixel_put(&mlx_data.image, new_point.x + offset_x, - new_point.y + offset_y, 0xFFFFFF00);
		// usleep(1000);
		new_point = ft_multiply_tuple_by_matrix(new_point, inv);
		i++;
	}
		mlx_put_image_to_window(mlx_data.mlx, mlx_data.win, mlx_data.image.img, 0, 0);

	mlx_loop(mlx_data.mlx);


	// printf("determinant = %f\n", ft_calculate_m3_determinant(m3_1));

}


