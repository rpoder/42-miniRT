/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:14:58 by margot            #+#    #+#             */
/*   Updated: 2022/12/01 02:30:35 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_sphere(t_data *data, char *line, t_parsing_tool *tool)
{
	t_sphere_values_tool	values;
	t_object				*new_sphere;

	tool->i = 2;
	if (nb_values_checker(line, 7, tool) != NO_ERR)
		return (tool->error);
	values.origin = get_coordinates(line, tool);
	if (tool->error != NO_ERR)
		return (tool->error);
	values.radius = get_one_parsing_value(line, tool) / 2;
	if (tool->error != NO_ERR)
		return (tool->error);
	values.color = get_color(line, tool);
	if (color_checker(values.color, line, tool) != NO_ERR)
		return (tool->error);
	new_sphere = create_sphere(data, values);
	if (!new_sphere)
	{
		tool->error = MALLOC_ERR;
		return (tool->error);
	}
	return (NO_ERR);
}

int	parse_triangle(t_data *data, char *line, t_parsing_tool *tool)
{
	t_triangle_values_tool	values;
	t_object				*new_triangle;

	tool->i = 2;
	if (nb_values_checker(line, 12, tool) != NO_ERR)
		return (tool->error);
	values.p1 = get_coordinates(line, tool);
	if (tool->error != NO_ERR)
		return (tool->error);
	values.p2 = get_coordinates(line, tool);
	if (tool->error != NO_ERR)
		return (tool->error);
	values.p3 = get_coordinates(line, tool);
	if (tool->error != NO_ERR)
		return (tool->error);
	values.color = get_color(line, tool);
	if (color_checker(values.color, line, tool) != NO_ERR)
		return (tool->error);
	new_triangle = create_triangle(data, values);
	if (!new_triangle)
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
	if (nb_values_checker(line, 7, tool) != NO_ERR)
		return (tool->error);
	values.origin = get_coordinates(line, tool);
	if (tool->error != NO_ERR)
		return (tool->error);
	values.radius = get_one_parsing_value(line, tool);
	if (tool->error != NO_ERR)
		return (tool->error);
	values.color = get_color(line, tool);
	if (color_checker(values.color, line, tool) != NO_ERR)
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
	bool					is_pattern;

	tool->i = 2;
	if (nb_values_checker(line, 10, tool) != NO_ERR)
		return (tool->error);
	values.origin = get_coordinates(line, tool);
	if (tool->error != NO_ERR)
		return (tool->error);
	values.orientation_vector = get_orientation_vector(line, tool);
	if (orientation_vector_checker(values.orientation_vector,
			line, tool) != NO_ERR)
		return (tool->error);
	values.color = get_color(line, tool);
	if (color_checker(values.color, line, tool) != NO_ERR)
		return (tool->error);
	is_pattern = get_is_pattern(line, tool);
	if (tool->error != NO_ERR)
		return (tool->error);
	new_plane = create_plane(data, values);
	if (!new_plane)
	{
		tool->error = MALLOC_ERR;
		return (tool->error);
	}
	if (is_pattern == true)
	{
		new_plane->material.texture_type = PATTERN_TEXTURE_TYPE;
		new_plane->material.pattern = create_checker_pattern(
			create_color(1, 1, 1), values.color);
	}
	return (NO_ERR);
}
