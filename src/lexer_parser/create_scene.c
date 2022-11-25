/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 22:26:42 by mpourrey          #+#    #+#             */
/*   Updated: 2022/11/25 18:32:24 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_light(t_data *data, char *line, t_parsing_tool *tool)
{
	t_tuple	origin;
	double	ratio;
	t_color	color;
	t_point_light	*light;

	origin = get_coordinates(line, tool);
	if (tool->ret != NO_ERR)
		return (tool->ret);
	ratio = get_one_parsing_value(line, tool);
	if (tool->ret != NO_ERR)
		return (tool->ret);
	color = get_color(line, tool);
	if (tool->ret != NO_ERR)
		return (tool->ret);
	color.red = color.red * ratio;
	color.green = color.green * ratio;
	color.blue = color.blue * ratio;
	light = create_point_light(data, color, origin);
	if (!light)
	{
		tool->ret = MALLOC_ERR;
		return (tool->ret);
	}
	return (tool->ret);
}

int	parse_ambient_light(t_data *data, char *line, t_parsing_tool *tool)
{
	double	ratio;
	t_color	color;
	t_color	ambient_light;

	tool->i = 2;
	ratio = get_one_parsing_value(line, tool);
	if (tool->ret != NO_ERR)
		return (tool->ret);
	color = get_color(line, tool);
	if (tool->ret != NO_ERR)
		return (tool->ret);
	ambient_light.red = color.red * ratio;
	ambient_light.green = color.green * ratio;
	ambient_light.blue = color.blue * ratio;
	data->world->ambient_light = ambient_light;
	return (NO_ERR);

}

int	parse_camera(t_data *data, char *line, t_parsing_tool *tool)
{
	t_parsing_values_tool	values;
	t_camera				*camera;

	values = set_parsing_values_tool(values);
	tool->i = 1;
	values.origin = get_coordinates(line, tool);
	if (tool->ret != NO_ERR)
		return (tool->ret);
	values.orientation_vector = get_orientation_vector(line, tool);
	if (tool->ret != NO_ERR)
		return (tool->ret);
	values.fov = get_one_parsing_value(line, tool);
	if (tool->ret != NO_ERR)
		return (tool->ret);
	camera = create_camera(data, CANVAS_X, CANVAS_Y, values);
	if (!camera)
	{
		tool->ret = MALLOC_ERR;
		return (tool->ret);
	}
	return (0);
}

int	create_scene(t_data *data, t_list *lst, t_parsing_tool *tool)
{
	while (lst)
	{
		set_parsing_tool(tool, 0, NO_ERR);
 		if (((char *)lst->content)[0] == 'C')
			parse_camera(data, (char *)lst->content, tool);
		else if (((char *)lst->content)[0] == 'A')
		 	parse_ambient_light(data, (char *)lst->content, tool);
		else if (((char *)lst->content)[0] == 'L')
			parse_light(data, (char *)lst->content, tool);
		else if (((char *)lst->content)[0] == 's' && ((char *)lst->content)[1] == 'p')
			parse_sphere(data, (char *)lst->content, tool);
 		else if (((char *)lst->content)[0] == 'p' && ((char *)lst->content)[1] == 'l')
			parse_plane(data, (char *)lst->content, tool);
		else if (((char *)lst->content)[0] == 'c' && ((char *)lst->content)[1] == 'y')
			parse_cylinder(data, (char *)lst->content, tool);
		else
			return (PARSING_ERR);
		if (tool-> ret != NO_ERR)
			return(tool->ret);
		lst = lst->next;
	}
	free(tool);
	return (NO_ERR);
}
