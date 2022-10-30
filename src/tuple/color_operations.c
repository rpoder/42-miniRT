/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:18:55 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/28 17:41:25 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	ft_create_color(double red, double green, double blue)
{
	t_color	new_color;

	new_color.red = red;
	new_color.green = green;
	new_color.blue = blue;
	return (new_color);
}

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

int	ft_convert_prime_color_to_int(double prime_color)
{
	int	new_prime_color;

	if (prime_color < 0)
		new_prime_color = 0;
	else if (prime_color > 1)
		new_prime_color = 255;
	else
		new_prime_color = prime_color * 255;
	return(new_prime_color);
}

long	ft_convert_color_to_longint(t_color rgb)
{
	long	color;

	color = 0;
	color += (long)ft_convert_prime_color_to_int(rgb.red) << 16;
	color += (long)ft_convert_prime_color_to_int(rgb.green) << 8;
	color += (long)ft_convert_prime_color_to_int(rgb.blue);
	// print_bits_of_long(color);
	return (color);
}
