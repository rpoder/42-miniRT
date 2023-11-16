/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:53:37 by margot            #+#    #+#             */
/*   Updated: 2022/12/02 19:38:35 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*skip_zero(char *str)
{
	int	i;

	i = 0;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
		str++;
	while (str[i] && str[i] == '0' && str[i + 1] && str[i + 1] != '.')
		i++;
	return (str + i);
}

int	ft_atof_checker(char *str)
{
	int		i;
	bool	has_comma;

	i = 0;
	has_comma = 0;
	str = skip_zero(str);
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
