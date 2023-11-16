/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 22:26:42 by mpourrey          #+#    #+#             */
/*   Updated: 2022/11/26 19:50:24 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	parse_if_camera(t_data *data, char *line, t_parsing_tool *tool)
{
	int	ret;

	ret = NO_ERR;
	if (line[0] == 'C' && ft_is_space(line[1]))
		ret = parse_camera(data, line, tool);
	else
	{
		ft_putstr_fd("Error \n Invalid object in your scene.rt, : ", 2);
		ft_putstr_fd(line, 2);
		return (PARSING_ERR);
	}
	return (ret);
}

static int	parse_if_light(t_data *data, char *line, t_parsing_tool *tool)
{
	int	ret;

	ret = NO_ERR;
	if (line[0] == 'A' && ft_is_space(line[1]))
		ret = parse_ambient_light(data, line, tool);
	else if (line[0] == 'L' && ft_is_space(line[1]))
		ret = parse_light(data, line, tool);
	else
	{
		ft_putstr_fd("Error\nERR :	 Invalid object in your scene.rt : ", 2);
		ft_putstr_fd(line, 2);
		return (PARSING_ERR);
	}
	return (ret);
}

static int	parse_if_object(t_data *data, char *line, t_parsing_tool *tool)
{
	int	ret;

	ret = NO_ERR;
	if (line[0] == 's' && line[1] == 'p' && ft_is_space(line[2]))
		ret = parse_sphere(data, line, tool);
	else if (line[0] == 'p' && line[1] == 'l' && ft_is_space(line[2]))
		ret = parse_plane(data, line, tool);
	else if (line[0] == 'c' && line[1] == 'y' && ft_is_space(line[2]))
		ret = parse_cylinder(data, line, tool);
	else
	{
		ft_putstr_fd("Error\nERR :	 Invalid object in your scene.rt : ", 2);
		ft_putstr_fd(line, 2);
		return (PARSING_ERR);
	}
	return (ret);
}

static int	parse_line(t_data *data, char *line, t_parsing_tool *tool)
{
	int	ret;

	ret = NO_ERR;
	if (line[0] == 'c' || line[0] == 's' || line[0] == 'p')
		ret = parse_if_object(data, line, tool);
	else if (line[0] == 'A' || line[0] == 'L')
		ret = parse_if_light(data, line, tool);
	else if (line[0] == 'C')
		ret = parse_if_camera(data, line, tool);
	else if (line[0] == '#')
	{
		ft_putstr_fd("WARN :	 Comment in your scene.rt : ", 2);
		ft_putstr_fd(line, 2);
	}
	else
	{
		ft_putstr_fd("Error\nERR :	 Invalid object in your scene.rt : ", 2);
		ft_putstr_fd(line, 2);
		ret = PARSING_ERR;
	}
	return (ret);
}

int	parse_scene(t_data *data, t_list *lst)
{
	int				ret;
	t_parsing_tool	*tool;
	char			*line;

	ret = NO_ERR;
	ret = check_scene_is_complete(lst);
	if (ret != NO_ERR)
		return (ret);
	tool = init_parsing_tool();
	if (!tool)
		return (MALLOC_ERR);
	while (lst)
	{
		tool = set_parsing_tool(tool);
		line = (char *)lst->content;
		ret = parse_line(data, line, tool);
		if (ret != NO_ERR)
			break ;
		lst = lst->next;
	}
	if (tool->str_value)
		free(tool->str_value);
	free(tool);
	return (ret);
}
