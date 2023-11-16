/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 00:33:46 by mpourrey          #+#    #+#             */
/*   Updated: 2022/12/02 19:12:38 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_cylinder_values_tool	get_cyl_values(char *line, t_parsing_tool *tool)
{
	t_cylinder_values_tool	values;

	values.origin = get_coordinates(line, tool);
	if (tool->error != NO_ERR)
		return (values);
	values.orientation_vector = get_orientation_vector(line, tool);
	if (orientation_vector_checker(values.orientation_vector,
			line, tool) != NO_ERR)
		return (values);
	values.radius = get_one_parsing_value(line, tool) / 2.0;
	if (tool->error != NO_ERR)
		return (values);
	values.height = get_one_parsing_value(line, tool);
	if (tool->error != NO_ERR)
		return (values);
	values.color = get_color(line, tool);
	if (color_checker(values.color, line, tool) != NO_ERR)
		return (values);
	return (values);
}

int	parse_cylinder(t_data *data, char *line, t_parsing_tool *tool)
{
	t_cylinder_values_tool	values;
	t_object				*new_cylinder;

	tool->i = 2;
	if (nb_values_checker(line, 11, tool) != NO_ERR)
		return (tool->error);
	values = get_cyl_values(line, tool);
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

static t_cone_values_tool	get_cone_values(char *line, t_parsing_tool *tool)
{
	t_cone_values_tool	values;

	values.origin = get_coordinates(line, tool);
	if (tool->error != NO_ERR)
		return (values);
	values.orientation_vector = get_orientation_vector(line, tool);
	if (orientation_vector_checker(values.orientation_vector,
			line, tool) != NO_ERR)
		return (values);
	values.radius = get_one_parsing_value(line, tool) / 2;
	if (tool->error != NO_ERR)
		return (values);
	values.color = get_color(line, tool);
	if (color_checker(values.color, line, tool) != NO_ERR)
		return (values);
	return (values);
}

int	parse_cone(t_data *data, char *line, t_parsing_tool *tool)
{
	t_cone_values_tool	values;
	t_object			*new_cone;

	tool->i = 2;
	if (nb_values_checker(line, 10, tool) != NO_ERR)
		return (tool->error);
	values = get_cone_values(line, tool);
	if (tool->error != NO_ERR)
		return (tool->error);
	new_cone = create_cone(data, values);
	if (!new_cone)
	{
		tool->error = MALLOC_ERR;
		return (tool->error);
	}
	return (NO_ERR);
}
