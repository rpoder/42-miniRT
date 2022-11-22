/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margot <margot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 22:26:42 by mpourrey          #+#    #+#             */
/*   Updated: 2022/11/22 23:38:09 by margot           ###   ########.fr       */
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
	radius = get_one_value(line, tool) / 2;
	if (tool->ret != NO_ERR)
		return (tool->ret);
	color = get_color(line, tool);
	if (tool->ret != NO_ERR)
		return (tool->ret);
	new_sphere = create_sphere(data, origin, radius);
	new_sphere->material.color = color;

	/* TEST */
	ft_print_tuple("origin", origin);
	printf("radius = %f\n", radius);
	ft_print_color("color", new_sphere->material.color);
	return (0);
}

int	parse_camera(t_data *data, char *line)
{
	int 	hsize;
	int		vsize;
	double	fov;
	
	create_camera(data, hsize, vsize, fov);
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
/* 		else if (((char *)lst->content)[0] == 'p' && ((char *)lst->content)[1] == 'l')
			parse_plane();
		else if (((char *)lst->content)[0] == 'c' && ((char *)lst->content)[1] == 'y')
			parse_cylinder(); */
		if (tool-> ret != NO_ERR)
			return(tool->ret);
		lst = lst->next;
		
	}
	free(tool);
	return (NO_ERR);
}
