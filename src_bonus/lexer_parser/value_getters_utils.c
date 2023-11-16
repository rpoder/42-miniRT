/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_getters_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 00:05:46 by mpourrey          #+#    #+#             */
/*   Updated: 2022/11/30 22:08:44 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	go_to_next_value(char *line, t_parsing_tool *tool)
{
	tool->i++;
	while (line[tool->i] && (line[tool->i - 1] != ','
			&& !ft_is_space(line[tool->i - 1])))
		tool->i++;
}

char	*get_parsing_value(int i, char *line)
{
	int		len;
	char	*p_value;
	int		j;

	len = 0;
	while (line[i + len] && !ft_is_space(line[i + len]) && line[i + len] != ',')
		len++;
	p_value = malloc(sizeof(char) * len + 1);
	if (!p_value)
		return (NULL);
	p_value[len] = '\0';
	j = 0;
	while (j < len)
	{
		p_value[j] = line[i + j];
		j++;
	}
	return (p_value);
}
