/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:37:48 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/30 17:08:42 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
	{
		ft_putstr_fd("ERR:	One argument is required.\n", 2);
		return (PARSING_ERR);
	}
	data = init_data();
	start_mlx(data);
	lexer_parser(data, argv[1]);
	print_world(data);
	render(data, data->world->camera, data->world);
	mlx_put_image_to_window(data->mlx_data->mlx, data->mlx_data->win,
		data->mlx_data->image.img, 0, 0);
	ft_putstr_fd("IMAGE DISPLAYED --------------------------------------\n", 2);
	mlx_loop(data->mlx_data->mlx);
	global_free(data, NO_ERR);
	return (0);
}
