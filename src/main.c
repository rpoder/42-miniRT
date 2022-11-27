/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:37:48 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/28 00:36:41 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	int		ret;

	// if (argc != 2)
	// {
	// 	ft_putstr_fd("ERR:	One argument is required.\n", 2);
	// 	return (PARSING_ERR);
	// }
	data = init_data();
	if (!data)
		return (MALLOC_ERR);

	data->mlx_data = start_mlx();
	if (!data->mlx_data)
		return (MALLOC_ERR);

	ret = lexer_parser(data, argv[1]);
	if (ret != NO_ERR)
		return (ret);
	print_world(data);
	render(data, data->world->camera, data->world);
	// my_mlx_pixel_put(&data->mlx_data->image, 433, 195, 0xffffffff);
	mlx_put_image_to_window(data->mlx_data->mlx, data->mlx_data->win,
		data->mlx_data->image.img, 0, 0);
	printf("IMAGE DISPLAYED ------------------------------------------------------------------------------------\n");
	mlx_loop(data->mlx_data->mlx);

	// t_ray					ray;
	// t_object				*tr1;
	// t_triangle_values_tool	tool;
	// t_intersections			intersections;

	// tool.p1 = create_tuple(0, 1, 0, 1);
	// tool.p2 = create_tuple(-1, 0, 0, 1);
	// tool.p3 = create_tuple(1, 0, 0, 1);

	// ray.origin = create_tuple(0, 0.5, -2, 1);
	// ray.direction = create_tuple(0, 0, 1, 0);

	// tr1 = create_triangle(data, tool);
	// intersections = get_triangle_intersections(tr1, ray);
	// print_intersection(intersections);

	return (0);
}
