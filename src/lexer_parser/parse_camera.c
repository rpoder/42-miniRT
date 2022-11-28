/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:12:46 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/28 17:13:07 by rpoder           ###   ########.fr       */
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
