/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool->error                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:47:53 by mpourrey          #+#    #+#             */
/*   Updated: 2022/11/29 15:56:14 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	nb_values_checker(char *line, int nb, t_parsing_tool *tool)
{
	int	i;

	i = tool->i;
	while (ft_is_space(line[i]))
		i++;
	while (line[i])
	{
		if (line[i] == ',' || ft_is_space(line[i]))
		{
			nb--;
			i++;
			while (line[i] && ft_is_space(line[i]))
				i++;
		}
		if (line[i])
			i++;
	}
	if (nb != 0)
	{
		ft_putstr_fd("ERR : Invalid nummber of values in line : ", 2);
		ft_putstr_fd(line, 2);
		tool->error = PARSING_ERR;
	}
	return (tool->error);
}

int	ratio_checker(double ratio, char *line, t_parsing_tool *tool)
{
	if (tool->error != NO_ERR)
		return (tool->error);
	if (ratio < 0.0 || ratio > 1.0)
	{
		ft_putstr_fd("ERR : Invalid ratio value ", 2);
		ft_putstr_fd("in your scene.rt in line : ", 2);
		ft_putstr_fd(line, 2);
		tool->error = PARSING_ERR;
	}
	return (tool->error);
}

int	color_checker(t_color color, char *line, t_parsing_tool *tool)
{
	if (tool->error != NO_ERR)
		return (tool->error);
	if (color.red < 0.0 || color.red > 1.0 || color.green < 0.0
		|| color.green > 1.0 || color.blue < 0.0 || color.blue > 1.0)
	{
		ft_putstr_fd("ERR : Invalid color value ", 2);
		ft_putstr_fd("in your scene.rt in line : ", 2);
		ft_putstr_fd(line, 2);
		tool->error = PARSING_ERR;
	}
	return (tool->error);
}

int	orientation_vector_checker(t_tuple or_v, char *line, t_parsing_tool *tool)
{
	if (tool->error != NO_ERR)
		return (tool->error);
	print_tuple("ori vector", or_v);
	if (or_v.x < -1.0 || or_v.x > 1.0 || or_v.y < -1.0 || or_v.y > 1.0
		|| or_v.z < -1.0 || or_v.z > 1.0)
	{
		ft_putstr_fd("ERR : Invalid orientation vector value ", 2);
		ft_putstr_fd("in your scene.rt in line : ", 2);
		ft_putstr_fd(line, 2);
		tool->error = PARSING_ERR;
	}
	return (tool->error);
}

int	fov_checker(double fov, char *line, t_parsing_tool *tool)
{
	if (tool->error != NO_ERR)
		return (tool->error);
	if (fov > 180.0 || fov < 0.0)
	{
		ft_putstr_fd("ERR : Invalid fov value in your scene.rt in line : ", 2);
		ft_putstr_fd(line, 2);
		tool->error = PARSING_ERR;
	}
	return (tool->error);
}
