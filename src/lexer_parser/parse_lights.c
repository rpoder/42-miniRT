/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lights.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 23:01:53 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/28 15:37:38 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_ambient_light(t_data *data, char *line, t_parsing_tool *tool)
{
	double	ratio;
	t_color	color;
	t_color	ambient_light;

	tool->i = 1;
	ratio = get_one_parsing_value(line, tool);
	if (tool->error != NO_ERR)
		return (tool->error);
	color = get_color(line, tool);
	if (tool->error != NO_ERR)
		return (tool->error);
	ambient_light.red = color.red * ratio;
	ambient_light.green = color.green * ratio;
	ambient_light.blue = color.blue * ratio;
	data->world->ambient_light = ambient_light;
	return (NO_ERR);
}

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
	color.red = color.red * ratio;
	color.green = color.green * ratio;
	color.blue =color.blue * ratio;
	light = create_point_light(data, color, origin);
	if (!light)
		return (MALLOC_ERR);
	return (NO_ERR);
}
