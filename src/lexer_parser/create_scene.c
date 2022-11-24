/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margot <margot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 22:26:42 by mpourrey          #+#    #+#             */
/*   Updated: 2022/11/23 20:07:05 by margot           ###   ########.fr       */
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
	color.blue = color.blue * ratio;
	color.green = color.green * ratio;
	color.red = color.red * ratio;
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

	ratio = get_one_parsing_value(line, tool);
	if (tool->ret != NO_ERR)
		return (tool->ret);
	color = get_color(line, tool);
	if (tool->ret != NO_ERR)
		return (tool->ret);
	//mettre ambient avec intensite dans world ?
	return (NO_ERR);
	
}

int	parse_camera(t_data *data, char *line, t_parsing_tool *tool)
{
	t_tuple	origin;
	t_tuple	orientation_vector;
	double	fov;
	t_camera	*camera;
	
	origin = get_coordinates(line, tool);
	if (tool->ret != NO_ERR)
		return (tool->ret);
	orientation_vector = get_orientation_vector(line, tool);
	if (tool->ret != NO_ERR)
		return (tool->ret);
	fov = get_one_parsing_value(line, tool);
	if (tool->ret != NO_ERR)
		return (tool->ret);	
	camera = create_camera(data, CANVAS_X, CANVAS_Y, fov);
	if (!camera)
	{
		tool->ret = MALLOC_ERR;
		return (tool->ret);
	}
	
	
	/* orientation */
//	data->world->camera->transform_m = compute_view_transform_m(from, origin, orientation_vector);
//	data->world->view_transform_m = compute_view_transform_m(from, to, up);
	return (0);
}

int	create_scene(t_data *data, t_list *lst, t_parsing_tool *tool)
{
	while (lst)
	{
		set_parsing_tool(tool, 0, NO_ERR);
/* 		if (((char *)lst->content)[0] == 'C')
			parse_camera(data, (char *)lst->content);
		else if (((char *)lst->content)[0] == 'A')
			parse_ambient_light();
		else if (((char *)lst->content)[0] == 'L')
			parse_light(); */
		if (((char *)lst->content)[0] == 's' && ((char *)lst->content)[1] == 'p')
			parse_sphere(data, (char *)lst->content, tool);
 		else if (((char *)lst->content)[0] == 'p' && ((char *)lst->content)[1] == 'l')
			parse_plane(data, (char *)lst->content, tool);
		else if (((char *)lst->content)[0] == 'c' && ((char *)lst->content)[1] == 'y')
			parse_cylinder(data, (char *)lst->content, tool); 
		if (tool-> ret != NO_ERR)
			return(tool->ret);
		lst = lst->next;
		
	}
	free(tool);
	return (NO_ERR);
}
