/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:18:55 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/30 17:51:36 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	add_colors(t_color a, t_color b)
{
	t_color	new_color;

	new_color.red = a.red + b.red;
	new_color.green = a.green + b.green;
	new_color.blue = a.blue + b.blue;
	return (new_color);
}

t_color	sub_colors(t_color a, t_color b)
{
	t_color	new_color;

	new_color.red = a.red - b.red;
	new_color.green = a.green - b.green;
	new_color.blue = a.blue - b.blue;
	return (new_color);
}

t_color	scale_color(t_color a, double scale)
{
	t_color	new_color;

	new_color.red = a.red * scale;
	new_color.green = a.green * scale;
	new_color.blue = a.blue * scale;
	return (new_color);
}

t_color	multiply_colors(t_color a, t_color b)
{
	t_color	new_color;

	new_color.red = a.red * b.red;
	new_color.green = a.green * b.green;
	new_color.blue = a.blue * b.blue;
	return (new_color);
}
