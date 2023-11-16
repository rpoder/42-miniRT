/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:12:46 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/30 00:12:08 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_camera(t_data *data, char *line, t_parsing_tool *tool)
{
	t_camera_values_tool	values;
	t_camera				*camera;

	tool->i = 1;
	if (nb_values_checker(line, 7, tool) != NO_ERR)
		return (tool->error);
	values.origin = get_coordinates(line, tool);
	if (tool->error != NO_ERR)
		return (tool->error);
	values.orientation_vector = get_orientation_vector(line, tool);
	if (orientation_vector_checker(values.orientation_vector,
			line, tool) != NO_ERR)
		return (tool->error);
	values.fov = (get_one_parsing_value(line, tool) * M_PI) / 180;
	if (fov_checker(values.fov, line, tool) != NO_ERR)
		return (tool->error);
	camera = create_camera(data, CANVAS_X, CANVAS_Y, values);
	if (!camera)
	{
		tool->error = MALLOC_ERR;
		return (tool->error);
	}
	return (0);
}
