/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:14:58 by margot            #+#    #+#             */
/*   Updated: 2022/11/26 22:32:14 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_sphere(t_data *data, char *line, t_parsing_tool *tool)
{
	t_sphere_values_tool	values;
	t_object				*new_sphere;

	tool->i = 2;
	values.origin = get_coordinates(line, tool);
	if (tool->error != NO_ERR)
		return (tool->error);
	values.radius = get_one_parsing_value(line, tool) / 2;
	if (tool->error != NO_ERR)
		return (tool->error);
	values.color = get_color(line, tool);
	if (tool->error != NO_ERR)
		return (tool->error);
	new_sphere = create_sphere(data, values);
	if (!new_sphere)
	{
		tool->error = MALLOC_ERR;
		return (tool->error);
	}
	return (NO_ERR);
}

int	parse_cylinder(t_data *data, char *line, t_parsing_tool *tool)
{
	t_cylinder_values_tool	values;
	t_object				*new_cylinder;

	tool->i = 2;
	values.origin = get_coordinates(line, tool);
	if (tool->error != NO_ERR)
		return (tool->error);
	values.orientation_vector = get_orientation_vector(line, tool);
	if (tool->error != NO_ERR)
		return (tool->error);
	values.radius = get_one_parsing_value(line, tool) / 2.0;
	if (tool->error != NO_ERR)
		return (tool->error);
	values.height = get_one_parsing_value(line, tool);
	if (tool->error != NO_ERR)
		return (tool->error);
	values.color = get_color(line, tool);
	if (tool->error != NO_ERR)
		return (tool->error);
	new_cylinder = create_cylinder(data, values);
	if (!new_cylinder)
	{
		tool->error = MALLOC_ERR;
		return (tool->error);
	}
	return (NO_ERR);
}

int	parse_cube(t_data *data, char *line, t_parsing_tool *tool)
{
	t_cube_values_tool		values;
	t_object				*new_cube;

	tool->i = 2;
	values.origin = get_coordinates(line, tool);
	if (tool->error != NO_ERR)
		return (tool->error);
	values.radius = get_one_parsing_value(line, tool);
	if (tool->error != NO_ERR)
		return (tool->error);
	values.color = get_color(line, tool);
	if (tool->error != NO_ERR)
		return (tool->error);
	new_cube = create_cube(data, values);
	if (!new_cube)
	{
		tool->error = MALLOC_ERR;
		return (tool->error);
	}
	return (NO_ERR);
}

int	parse_plane(t_data *data, char *line, t_parsing_tool *tool)
{
	t_plane_values_tool		values;
	t_object				*new_plane;

	tool->i = 2;
	values.origin = get_coordinates(line, tool);
	if (tool->error != NO_ERR)
		return (tool->error);
	values.orientation_vector = get_orientation_vector(line, tool);
	if (tool->error != NO_ERR)
		return (tool->error);
	values.color = get_color(line, tool);
	if (tool->error != NO_ERR)
		return (tool->error);
	new_plane = create_plane(data, values);
	if (!new_plane)
	{
		tool->error = MALLOC_ERR;
		return (tool->error);
	}
	return (NO_ERR);
}

