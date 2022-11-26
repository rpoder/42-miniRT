/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:37:48 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/26 23:16:03 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{

	t_tuple	from;
	t_tuple	to;
	t_tuple	tmp;
	t_tuple	up;
 	t_object			*s1;
	t_object			*s2;
	t_object			*c1;
	t_object			*p1;
	t_point_light		*light;

	t_tuple				parsing_origin;
	t_tuple				parsing_orientation;
	t_ray				parsing_ray;

	////////////////////////////////////////////////////////
	t_data	*data;
	int		ret;

	if (argc != 2)
	{
		ft_putstr_fd("ERR:	One argument is required.\n", 2);
		return (PARSING_ERR);
	}
	data = init_data();
	if (!data)
		return (MALLOC_ERR);

	data->mlx_data = start_mlx();
	if (!data->mlx_data)
		return (MALLOC_ERR);

	ret = lexer_parser(data, argv[1]);
	if (ret != NO_ERR)
		return (ret);
	///////////////////////////////////////////////////
	create_camera(data, CANVAS_X, CANVAS_Y, M_PI/2);

	parsing_origin = create_tuple(0, 0, -10, 1);
	parsing_orientation = create_tuple(0, 0, 1, 0);

	to = ft_add_tuples(parsing_origin, parsing_orientation);
	// ft_print_tuple("to", to);

	tmp = ft_multiply_tuples(create_tuple(0, 1, 0, 0), to);
	if (ft_tuple_scalarproduct(create_tuple(0, 0, 1, 0), ft_normalize_tuple(parsing_orientation)) >= 0.0)
		tmp = ft_neg_tuple(tmp);
	// ft_print_tuple("tmp", tmp);

	up = ft_normalize_tuple(ft_multiply_tuples(parsing_orientation, tmp));
	// ft_print_tuple("up", up);

	// printf("dot product %f\n", ft_tuple_scalarproduct(create_tuple(0, 1, 0, 0), ft_normalize_tuple(parsing_orientation)));
	data->world->camera->transform_m = compute_view_transform_m(parsing_origin, to, up);

	// light = create_point_light(data, create_color(0, 0, 0), create_tuple(10, 5, -10, 1));

	print_world(data);
	render(data, data->world->camera, data->world);

	mlx_put_image_to_window(data->mlx_data->mlx, data->mlx_data->win,
		data->mlx_data->image.img, 0, 0);
	printf("IMAGE DISPLAYED ------------------------------------------------------------------------------------\n");
	mlx_loop(data->mlx_data->mlx);

	return (0);
}
