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

int	parse_camera(t_data *data, char *line, t_parsing_tool *tool)
{
	t_camera_values_tool	values;
	t_camera				*camera;

	tool->i = 1;
	values.origin = get_coordinates(line, tool);
	if (tool->error != NO_ERR)
		return (tool->error);
	values.orientation_vector = get_orientation_vector(line, tool);
	if (tool->error != NO_ERR)
		return (tool->error);
	values.fov = (get_one_parsing_value(line, tool) * M_PI) / 180;
	if (tool->error != NO_ERR)
		return (tool->error);
	camera = create_camera(data, CANVAS_X, CANVAS_Y, values);
	if (!camera)
	{
		tool->error = MALLOC_ERR;
		return (tool->error);
	}
	return (0);
}

int	parse_scene(t_data *data, t_list *lst)
{
	int				ret;
	t_parsing_tool	*tool;

	ret = NO_ERR;
	tool = init_parsing_tool();
	if (!tool)
		return (MALLOC_ERR);
	while (lst)
	{
		if (((char *)lst->content)[0] == 'c' && ((char *)lst->content)[1] == 'u')
			ret = parse_cube(data, (char *)lst->content, tool);
		else if (((char *)lst->content)[0] == 's' && ((char *)lst->content)[1] == 'p')
			ret = parse_sphere(data, (char *)lst->content, tool);
 		else if (((char *)lst->content)[0] == 'p' && ((char *)lst->content)[1] == 'l')
			ret = parse_plane(data, (char *)lst->content, tool);
		else if (((char *)lst->content)[0] == 'c' && ((char *)lst->content)[1] == 'y')
			ret = parse_cylinder(data, (char *)lst->content, tool);
		else if (((char *)lst->content)[0] == 't' && ((char *)lst->content)[1] == 'r')
			ret = parse_triangle(data, (char *)lst->content, tool);
		else if (((char *)lst->content)[0] == 'L')
			ret = parse_light(data, (char *)lst->content, tool);
		else if (((char *)lst->content)[0] == 'A')
			ret = parse_ambient_light(data, (char *)lst->content, tool);
		else if (((char *)lst->content)[0] == 'C')
			ret = parse_camera(data, (char *)lst->content, tool);
		else if (((char *)lst->content)[0] == '#')
		{
			ft_putstr_fd("ERR : No object match on line :\n", 2);
			ft_putstr_fd((char *)lst->content, 2);
		}
		else
		{
			free(tool);
			return (PARSING_ERR);
		}
		if (ret != NO_ERR)
			break ;
		lst = lst->next;
	}
	free(tool);
	return (ret);
}


