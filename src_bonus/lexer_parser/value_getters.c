/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_getters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 22:32:37 by margot            #+#    #+#             */
/*   Updated: 2022/12/01 02:25:17 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	get_is_pattern(char *line, t_parsing_tool *tool)
{
	bool	is_pattern;

	while (line[tool->i] && ft_is_space(line[tool->i]))
		tool->i++;
	tool->str_value = get_parsing_value(tool->i, line);
	if (line[tool->i] == 'y')
		is_pattern = true;
	else if (line[tool->i] == 'n')
		is_pattern = false;
	else
	{
		tool->error = PARSING_ERR;
		print_value_error(tool->str_value, line);
		return (false);
	}
	if (line[tool->i + 1] && !ft_is_space(line[tool->i + 1]))
	{
		tool->error = PARSING_ERR;
		print_value_error(tool->str_value, line);
		return (false);
	}
	return (is_pattern);
}

t_color	get_color(char *line, t_parsing_tool *tool)
{
	double	color[3];

	tool->count = 0;
	while (tool->count < 3)
	{
		while (line[tool->i] && ft_is_space(line[tool->i]))
			tool->i++;
		tool->str_value = get_parsing_value(tool->i, line);
		if (str_value_checker(tool->str_value, line, tool) != NO_ERR)
			return (create_color(0, 0, 0));
		if (ft_atof_checker(tool->str_value) != 1)
		{
			tool->error = PARSING_ERR;
			print_value_error(tool->str_value, line);
			return (create_color(0, 0, 0));
		}
		color[tool->count] = ft_atof(tool->str_value);
		go_to_next_value(line, tool);
		tool->count++;
		free(tool->str_value);
	}
	return (create_color(color[0] / 255.0, color[1] / 255.0, color[2] / 255.0));
}

t_tuple	get_orientation_vector(char *line, t_parsing_tool *tool)
{
	double	coordinates[3];

	tool->count = 0;
	while (tool->count < 3)
	{
		while (line[tool->i] && ft_is_space(line[tool->i]))
			tool->i++;
		tool->str_value = get_parsing_value(tool->i, line);
		if (str_value_checker(tool->str_value, line, tool) != NO_ERR)
			return (create_tuple(0, 0, 0, 0));
		if (ft_atof_checker(tool->str_value) != 1)
		{
			print_value_error(tool->str_value, line);
			return (create_tuple(0, 0, 0, 0));
		}
		coordinates[tool->count] = ft_atof(tool->str_value);
		go_to_next_value(line, tool);
		tool->count++;
		free(tool->str_value);
	}
	return (create_tuple(coordinates[0], coordinates[1], coordinates[2], 0.0));
}

t_tuple	get_coordinates(char *line, t_parsing_tool *tool)
{
	double	coordinates[3];

	tool->count = 0;
	while (tool->count < 3)
	{
		while (line[tool->i] && ft_is_space(line[tool->i]))
			tool->i++;
		tool->str_value = get_parsing_value(tool->i, line);
		if (str_value_checker(tool->str_value, line, tool) != NO_ERR)
			return (create_tuple(0, 0, 0, 0));
		if (ft_atof_checker(tool->str_value) != 1)
		{
			print_value_error(tool->str_value, line);
			return (create_tuple(0, 0, 0, 0));
		}
		coordinates[tool->count] = ft_atof(tool->str_value);
		go_to_next_value(line, tool);
		tool->count++;
		free(tool->str_value);
	}
	return (create_tuple(coordinates[0], coordinates[1], coordinates[2], 1.0));
}

double	get_one_parsing_value(char *line, t_parsing_tool *tool)
{
	double	double_value;

	while (line[tool->i] && ft_is_space(line[tool->i]))
		tool->i++;
	tool->str_value = get_parsing_value(tool->i, line);
	if (str_value_checker(tool->str_value, line, tool) != NO_ERR)
		return (0.0);
	if (ft_atof_checker(tool->str_value) != 1 || tool->str_value[0] == '-')
	{
		print_value_error(tool->str_value, line);
		return (0.0);
	}
	double_value = ft_atof(tool->str_value);
	tool->i++;
	while (line[tool->i] && !ft_is_space(line[tool->i - 1]))
		tool->i++;
	free(tool->str_value);
	return (double_value);
}
