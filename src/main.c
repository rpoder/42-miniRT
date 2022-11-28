/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:37:48 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/28 13:02:40 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
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
	data->mlx_data = start_mlx(data);
	if (!data->mlx_data)
		global_free(data, MALLOC_ERR);
	ret = lexer_parser(data, argv[1]);
	if (ret != NO_ERR)
		return (ret);
	print_world(data);
//	render(data, data->world->camera, data->world);
	mlx_put_image_to_window(data->mlx_data->mlx, data->mlx_data->win,
		data->mlx_data->image.img, 0, 0);
	printf("IMAGE DISPLAYED ------------------------------------------------------------------------------------\n");
	mlx_loop(data->mlx_data->mlx);

	return (0);
}
