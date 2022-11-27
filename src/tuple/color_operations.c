/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:18:55 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/27 16:34:21 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	ft_add_colors(t_color a, t_color b)
{
	t_color	new_color;

	new_color.red = a.red + b.red;
	new_color.green = a.green + b.green;
	new_color.blue = a.blue + b.blue;
	return (new_color);
}

t_color	ft_sub_colors(t_color a, t_color b)
{
	t_color	new_color;

	new_color.red = a.red - b.red;
	new_color.green = a.green - b.green;
	new_color.blue = a.blue - b.blue;
	return (new_color);
}

t_color	ft_scale_color(t_color a, double scale)
{
	t_color	new_color;

	new_color.red = a.red * scale;
	new_color.green = a.green * scale;
	new_color.blue = a.blue * scale;
	return (new_color);
}

t_color	ft_multiply_colors(t_color a, t_color b)
{
	t_color	new_color;

	new_color.red = a.red * b.red;
	new_color.green = a.green * b.green;
	new_color.blue = a.blue * b.blue;
	return (new_color);
}
