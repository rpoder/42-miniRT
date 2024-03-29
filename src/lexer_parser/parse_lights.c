/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lights.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 23:01:53 by rpoder            #+#    #+#             */
/*   Updated: 2022/12/02 01:46:58 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_ambient_light(t_data *data, char *line, t_parsing_tool *tool)
{
	t_light_values_tool	values;
	t_color				ambient_light;

	tool->i = 1;
	if (nb_values_checker(line, 4, tool) != NO_ERR)
		return (tool->error);
	values.ratio = get_one_parsing_value(line, tool);
	if (ratio_checker(values.ratio, line, tool) != NO_ERR)
		return (tool->error);
	values.color = get_color(line, tool);
	if (color_checker(values.color, line, tool) != NO_ERR)
		return (tool->error);
	ambient_light.red = values.color.red * values.ratio;
	ambient_light.green = values.color.green * values.ratio;
	ambient_light.blue = values.color.blue * values.ratio;
	data->world->ambient_light = ambient_light;
	return (NO_ERR);
}

int	parse_light(t_data *data, char *line, t_parsing_tool *tool)
{
	t_light_values_tool	values;
	t_point_light		*light;

	tool->i = 1;
	if (nb_values_checker(line, 4, tool) != NO_ERR)
		return (tool->error);
	values.origin = get_coordinates(line, tool);
	if (tool->error != NO_ERR)
		return (tool->error);
	values.ratio = get_one_parsing_value(line, tool);
	if (ratio_checker(values.ratio, line, tool) != NO_ERR)
		return (tool->error);
	values.color.red = 1 * values.ratio;
	values.color.green = 1 * values.ratio;
	values.color.blue = 1 * values.ratio;
	light = create_point_light(data, values.color, values.origin);
	if (!light)
		return (MALLOC_ERR);
	return (NO_ERR);
}
