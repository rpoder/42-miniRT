/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:43:59 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/30 17:52:03 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	create_color(double red, double green, double blue)
{
	t_color	new_color;

	new_color.red = red;
	new_color.green = green;
	new_color.blue = blue;
	return (new_color);
}

int	convert_prime_color_to_int(double prime_color)
{
	int	new_prime_color;

	if (prime_color < 0)
		new_prime_color = 0;
	else if (prime_color > 1)
		new_prime_color = 255;
	else
		new_prime_color = prime_color * 255;
	return (new_prime_color);
}

long	convert_color_to_longint(t_color rgb)
{
	long	color;

	color = 0;
	color += (long)convert_prime_color_to_int(rgb.red) << 16;
	color += (long)convert_prime_color_to_int(rgb.green) << 8;
	color += (long)convert_prime_color_to_int(rgb.blue);
	return (color);
}
