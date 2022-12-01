/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_values_checker_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 00:16:08 by mpourrey          #+#    #+#             */
/*   Updated: 2022/12/01 01:49:16 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_value_error(char *value, char *line)
{
	ft_putstr_fd("Error\nERR :	 Invalid value ", 2);
	ft_putstr_fd(value, 2);
	ft_putstr_fd(" in your scene.rt in line : ", 2);
	ft_putstr_fd(line, 2);
}

int	str_value_checker(char *str_value, char *line, t_parsing_tool *tool)
{
	if (!tool->str_value)
		tool->error = MALLOC_ERR;
	if (tool->str_value && tool->str_value[0] == '\0')
	{
		print_value_error(str_value, line);
		tool->error = PARSING_ERR;
		free(str_value);
	}
	return (tool->error);
}
