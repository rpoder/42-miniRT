/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:37:48 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/21 13:49:41 by rpoder           ###   ########.fr       */
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

	// my_mlx_pixel_put(&mlx_data.image, 10, 10, 0xFFFF0000);
	// mlx_put_image_to_window(mlx_data.mlx, mlx_data.win, mlx_data.image.img, 0, 0);
	// printf("coucou\n");
	// mlx_loop(mlx_data.mlx);

	// float	matrix[4][4];
	// float	new_matrix[4][4];

	// ft_copy_matrix(matrix, new_matrix);
	// printf("matrix %p\n", matrix);

	t_matrix4	m4_1;

	m4_1.matrix[0][0] = -2;
	m4_1.matrix[0][1] = -8;
	m4_1.matrix[0][2] = 3;
	m4_1.matrix[0][3] = 5;

	m4_1.matrix[1][0] = -3;
	m4_1.matrix[1][1] = 1;
	m4_1.matrix[1][2] = 7;
	m4_1.matrix[1][3] = 3;

	m4_1.matrix[2][0] = 1;
	m4_1.matrix[2][1] = 2;
	m4_1.matrix[2][2] = -9;
	m4_1.matrix[2][3] = 6;

	m4_1.matrix[3][0] = -6;
	m4_1.matrix[3][1] = 7;
	m4_1.matrix[3][2] = 7;
	m4_1.matrix[3][3] = -9;


	ft_print_matrix4(m4_1);
	printf("determinant = %f\n", ft_calculate_m4_determinant(m4_1));

	// t_matrix3	m3_1;

	// m3_1.matrix[0][0] = -3;
	// m3_1.matrix[0][1] = 7;
	// m3_1.matrix[0][2] = 3;

	// m3_1.matrix[1][0] = 1;
	// m3_1.matrix[1][1] = -9;
	// m3_1.matrix[1][2] = 6;

	// m3_1.matrix[2][0] = -6;
	// m3_1.matrix[2][1] = 7;
	// m3_1.matrix[2][2] = -9;

	// ft_print_matrix3(m3_1);
	// printf("determinant = %f\n", ft_calculate_m3_determinant(m3_1));
}


