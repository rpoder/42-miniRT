/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margot <margot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:14:58 by margot            #+#    #+#             */
/*   Updated: 2022/11/23 19:39:13 by margot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


int	parse_sphere(t_data *data, char *line, t_parsing_tool *tool)
{
	t_tuple		origin;
	double		radius;
	t_color		color;
	t_object	*new_sphere;

	origin = get_coordinates(line, tool);
	if (tool->ret != NO_ERR)
		return (tool->ret);
	radius = get_one_parsing_value(line, tool) / 2;
	if (tool->ret != NO_ERR)
		return (tool->ret);
	color = get_color(line, tool);
	if (tool->ret != NO_ERR)
		return (tool->ret);
	/* scaling et translation */
	new_sphere = create_sphere(data, origin, radius);
	if (!new_sphere)
	{
		tool->ret = MALLOC_ERR;
		return (tool->ret);
	}
	
	/* couleur */
	new_sphere->material.color = color;

	/* TEST */
	printf("\nSPHERE\n");
	ft_print_tuple("origin", origin);
	printf("radius = %f\n", radius);
	ft_print_color("color", new_sphere->material.color);
	return (0);
}

int	parse_cylinder(t_data *data, char *line, t_parsing_tool *tool)
{
	t_tuple		origin;
	t_tuple		orientation_vector;
	double		radius;
	double		height;
	t_color		color;
	t_object	*new_cylinder;

	origin = get_coordinates(line, tool);
	if (tool->ret != NO_ERR)
		return (tool->ret);
	orientation_vector = get_orientation_vector(line, tool);
	if (tool->ret != NO_ERR)
		return (tool->ret);
	radius = get_one_parsing_value(line, tool) / 2.0;
	if (tool->ret != NO_ERR)
		return (tool->ret);
	height = get_one_parsing_value(line, tool);
	if (tool->ret != NO_ERR)
		return (tool->ret);
	color = get_color(line, tool);
	if (tool->ret != NO_ERR)
		return (tool->ret);
		
	/* scaling et translation */
	new_cylinder = create_cylinder(data, origin, radius, height);
	if (!new_cylinder)
	{
		tool->ret = MALLOC_ERR;
		return (tool->ret);
	}
	/* orientation et couleur */
	transform_cylinder_orientation(new_cylinder, orientation_vector);
	new_cylinder->material.color = color;

	/* TEST */
	printf("\nCYLINDER\n");
	ft_print_tuple("origin", origin);
	ft_print_tuple("orientation vector", orientation_vector);
	printf("radius = %f\n", radius);
	printf("height %f\n", height);
	printf("max %f | min %f\n", new_cylinder->max, new_cylinder->min);
	ft_print_color("color", new_cylinder->material.color);
	return (0);
}

int	parse_plane(t_data *data, char *line, t_parsing_tool *tool)
{
	t_tuple		origin;
	t_tuple		orientation_vector;
	t_object	*new_plane;
		
	origin = get_coordinates(line, tool);
	if (tool->ret != NO_ERR)
		return (tool->ret);
	orientation_vector = get_orientation_vector(line, tool);
	if (tool->ret != NO_ERR)
		return (tool->ret);
	new_plane = create_plane(data, origin);
	if (!new_plane)
	{
		tool->ret = MALLOC_ERR;
		return (tool->ret);
	}
	/* orientation */
	transform_plane_orientation(new_plane, orientation_vector);

	return (0);
}