/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:43:59 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/30 15:44:49 by rpoder           ###   ########.fr       */
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
