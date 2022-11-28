/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_getters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 22:32:37 by margot            #+#    #+#             */
/*   Updated: 2022/11/28 18:49:01 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static char	*get_parsing_value(int i, char *line)
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

t_color get_color(char *line, t_parsing_tool *tool)
{
	int		count;
	char	*str_value;
	double	double_value;
	double	color[3];

	count = 0;
	while (count < 3)
	{
		while (line[tool->i] && ft_is_space(line[tool->i]))
			tool->i++;
		str_value = get_parsing_value(tool->i, line);
		if (!str_value)
		{
			tool->error = MALLOC_ERR;
			return (create_color(0, 0, 0));
		}
		if (ft_atof_checker(str_value) != 1)
		{
			printf("ERR : %s in your scene.rt is not a valid value\n", str_value);
			tool->error = PARSING_ERR;
			free(str_value);
			return (create_color(0, 0, 0));
		}
		color[count] = ft_atof(str_value);
		tool->i++;
		while (line[tool->i] && (line[tool->i - 1] != ',' && !ft_is_space(line[tool->i - 1])))
			tool->i++;
		count++;
		free(str_value);
	}
	return (create_color(color[0] / 255.0, color[1] / 255.0, color[2] / 255.0));
}

t_tuple get_orientation_vector(char *line, t_parsing_tool *tool)
{
	int		count;
	char	*str_value;
	double	double_value;
	double	coordinates[3];

	count = 0;
	while (count < 3)
	{
		while (line[tool->i] && ft_is_space(line[tool->i]))
			tool->i++;
		str_value = get_parsing_value(tool->i, line);
		if (!str_value)
		{
			tool->error = MALLOC_ERR;
			return (create_tuple(0, 0, 0, 0));
		}
		if (str_value[0] == '\0')
		{
			printf("ERR : invalid line in your scene.rt : %s", line);
			free(str_value);
			tool->error = PARSING_ERR;
			return (create_tuple(0, 0, 0, 0));
		}
		if (ft_atof_checker(str_value) != 1)
		{
			printf("ERR : %s in your scene.rt is not a valid value\n", str_value);
			tool->error = PARSING_ERR;
			free(str_value);
			return (create_tuple(0, 0, 0, 0));
		}
		coordinates[count] = ft_atof(str_value);
		tool->i++;
		while (line[tool->i] && (line[tool->i - 1] != ',' && !ft_is_space(line[tool->i - 1])))
			tool->i++;
		count++;
		free(str_value);
	}
	return (create_tuple(coordinates[0], coordinates[1], coordinates[2], 0.0));
}

t_tuple get_coordinates(char *line, t_parsing_tool *tool)
{
	int		count;
	char	*str_value;
	double	double_value;
	double	coordinates[3];

	count = 0;
	while (count < 3)
	{
		while (line[tool->i] && ft_is_space(line[tool->i]))
			tool->i++;
		str_value = get_parsing_value(tool->i, line);
		if (!str_value)
		{
			tool->error = MALLOC_ERR;
			return (create_tuple(0, 0, 0, 0));
		}
		if (str_value[0] == '\0')
		{
			printf("ERR : invalid line in your scene.rt : %s", line);
			free(str_value);
			tool->error = PARSING_ERR;
			return (create_tuple(0, 0, 0, 0));
		}
		if (ft_atof_checker(str_value) != 1)
		{
			printf("ERR : %s in your scene.rt is not a valid value\n", str_value);
			tool->error = PARSING_ERR;
			free(str_value);
			return (create_tuple(0, 0, 0, 0));
		}
		coordinates[count] = ft_atof(str_value);
		tool->i++;
		while (line[tool->i] && (line[tool->i - 1] != ',' && !ft_is_space(line[tool->i - 1])))
			tool->i++;
		count++;
		free(str_value);
	}
	return (create_tuple(coordinates[0], coordinates[1], coordinates[2], 1.0));
}

double	get_one_parsing_value(char *line, t_parsing_tool *tool)
{
	char	*str_value;
	double	double_value;

	while (line[tool->i] && ft_is_space(line[tool->i]))
		tool->i++;
	str_value = get_parsing_value(tool->i, line);
	if (!str_value)
	{
		tool->error = MALLOC_ERR;
		return (0.0);
	}
	if (ft_atof_checker(str_value) != 1)
	{
		printf("ERR : %s in your scene.rt is not a valid value\n", str_value);
		tool->error = PARSING_ERR;
		free(str_value);
		return (0.0);
	}
	double_value = ft_atof(str_value);
	tool->i++;
	while (line[tool->i] && !ft_is_space(line[tool->i - 1]))
		tool->i++;
	free(str_value);
	return (double_value);
}
