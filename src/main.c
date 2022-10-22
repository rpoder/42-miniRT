/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:37:48 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/22 19:12:12 by rpoder           ###   ########.fr       */
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


	t_tuple				p;
	t_tuple				p2;
	t_tuple				p3;
	t_matrix4			t1;
	t_matrix4			t2;
	t_tuple				new_point;
	int					offset_x;
	int					offset_y;
	int					i;
	int					j;
	t_shearing_values	shearing;

	shearing.xy = 0;
	shearing.xz = 1;
	shearing.yx = 0;
	shearing.yz = 0;
	shearing.zx = 0;
	shearing.zy = 0;

	p = ft_create_tuple(0, 100, 0, 1);
	offset_x = 300;
	offset_y = 300;
	i = 0;
	j = 0;

	p2 = p;
	while(j < 8)
	{

		t1= ft_get_shear_matrix(shearing);
		p2 = ft_multiply_tuple_by_matrix(p2, t1);
		ft_print_tuple("p2", p2);
		i = 0;
		p3 = p2;
		while (i < 24)
		{
			// usleep(1000);
			t2= ft_get_rotate_z_matrix(M_PI / 12);
			p3 = ft_multiply_tuple_by_matrix(p3, t2);
			my_mlx_pixel_put(&mlx_data.image, p3.x + offset_x, p3.y + offset_y, 0xFFFFFF00);
			i++;
		}
		j++;
	}

	mlx_put_image_to_window(mlx_data.mlx, mlx_data.win, mlx_data.image.img, 0, 0);
	mlx_loop(mlx_data.mlx);

	// printf("determinant = %f\n", ft_calculate_m3_determinant(m3_1));

}


