/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 13:11:02 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/30 13:15:29 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	create_world(t_data *data, int fd)
{
	t_point_light	light;

	light = ft_create_point_light(ft_create_color(1, 1, 1), ft_create_tuple(-10, 10, -10));
}
