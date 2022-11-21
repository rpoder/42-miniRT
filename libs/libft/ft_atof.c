/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margot <margot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:22:04 by margot            #+#    #+#             */
/*   Updated: 2022/11/21 19:12:28 by margot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	compute_decimal(char *str, int i)
{
	int		j;
	double	decimal;
	
	j = 0;
	decimal = 0.0;
	while (str[i + j])
	{
		decimal = decimal * 10 + ((double)str[i + j] - 48);
		j++;
		
	}
	while (j > 0)
	{
		decimal = decimal / 10;
		j--;
	}
	return (decimal);
}

/* part du principe que l'argument est valide */
double	ft_atof(char *str)
{
	double	nb;
	double	decimal;
	double	sign;
	int		i;

	i = 0;
	sign = 1.0;
	nb = 0.0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		str++;
	}
	i = 0;
	while(str[i] && str[i] != '.')
	{
		nb = nb * 10 + ((double)str[i] - 48);
		i++;
	}
	if (!str[i])
		return (nb); 
	else
		decimal = compute_decimal(str, i + 1);
	return((nb + decimal) * sign);
}
