/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:14:58 by margot            #+#    #+#             */
/*   Updated: 2022/11/25 19:05:35 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_sphere(t_data *data, char *line, t_parsing_tool *tool)
{
	t_parsing_values_tool	values;
	t_object				*new_sphere;

	values = set_parsing_values_tool(values);
	values.origin = get_coordinates(line, tool);
	if (tool->ret != NO_ERR)
		return (tool->ret);
	values.radius = get_one_parsing_value(line, tool) / 2;
	if (tool->ret != NO_ERR)
		return (tool->ret);
	values.color = get_color(line, tool);
	if (tool->ret != NO_ERR)
		return (tool->ret);
	new_sphere = create_sphere(data, values);
	if (!new_sphere)
	{
		tool->ret = MALLOC_ERR;
		return (tool->ret);
	}
	/* TEST */
	// printf("\nSPHERE\n");
	// ft_print_tuple("origin", origin);
	// printf("radius = %f\n", radius);
	// ft_print_color("color", new_sphere->material.color);
	return (0);
}

int	parse_cylinder(t_data *data, char *line, t_parsing_tool *tool)
{
	t_parsing_values_tool	values;
	t_object				*new_cylinder;

	values.origin = get_coordinates(line, tool);
	if (tool->ret != NO_ERR)
		return (tool->ret);
	values.orientation_vector = get_orientation_vector(line, tool);
	if (tool->ret != NO_ERR)
		return (tool->ret);
	values.radius = get_one_parsing_value(line, tool) / 2.0;
	if (tool->ret != NO_ERR)
		return (tool->ret);
	values.height = get_one_parsing_value(line, tool);
	if (tool->ret != NO_ERR)
		return (tool->ret);
	values.color = get_color(line, tool);
	if (tool->ret != NO_ERR)
		return (tool->ret);
	new_cylinder = create_cylinder(data, values);
	if (!new_cylinder)
	{
		tool->ret = MALLOC_ERR;
		return (tool->ret);
	}
	/* TEST */
	// printf("\nCYLINDER\n");
	// ft_print_tuple("origin", origin);
	// ft_print_tuple("orientation vector", orientation_vector);
	// printf("radius = %f\n", radius);
	// printf("height %f\n", height);
	// printf("max %f | min %f\n", new_cylinder->max, new_cylinder->min);
	// ft_print_color("color", new_cylinder->material.color);
	return (0);
}

int	parse_plane(t_data *data, char *line, t_parsing_tool *tool)
{
	t_parsing_values_tool	values;
	t_object				*new_plane;

	values.origin = get_coordinates(line, tool);
	if (tool->ret != NO_ERR)
		return (tool->ret);
	values.orientation_vector = get_orientation_vector(line, tool);
	if (tool->ret != NO_ERR)
		return (tool->ret);
	new_plane = create_plane(data, values);
	if (!new_plane)
	{
		tool->ret = MALLOC_ERR;
		return (tool->ret);
	}
	return (0);
}
