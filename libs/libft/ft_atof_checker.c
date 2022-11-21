/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margot <margot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:53:37 by margot            #+#    #+#             */
/*   Updated: 2022/11/21 19:11:57 by margot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atof_checker(char *str)
{
	int		i;
	bool	has_comma;

	i = 0;
	has_comma = 0;
	if (str[i] == '-' || str[i] == '+')
		str++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			if (i > 10 && has_comma == 0)
				return (-1);
			if (str[i] == '.' && i != 0 && str[i + 1] != '\0' && has_comma == 0)
			{
				has_comma = 1;
				i++;
			}
			else
				return (-1);
		}
		else
			i++;
	}
	return (1);
}