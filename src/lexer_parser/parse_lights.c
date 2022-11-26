/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lights.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 23:01:53 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/26 23:18:54 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_light(t_data *data, char *line, t_parsing_tool *tool)
{
	t_tuple			origin;
	double			ratio;
	t_color			color;
	t_point_light	*light;

	tool->i = 1;
	origin = get_coordinates(line, tool);
	if (tool->error != NO_ERR)
		return (tool->error);
	ratio = get_one_parsing_value(line, tool);
	if (tool->error != NO_ERR)
		return (tool->error);
	color = get_color(line, tool);
	if (tool->error != NO_ERR)
		return (tool->error);
	ft_print_color("color", color);
	color.red = color.red * ratio;
	color.green = color.green * ratio;
	color.blue =color.blue * ratio;
	ft_print_tuple("origin", origin);
	ft_print_color("color", color);
	light = create_point_light(data, color, origin);
	if (!light)
		return (MALLOC_ERR);
	return (NO_ERR);
}
