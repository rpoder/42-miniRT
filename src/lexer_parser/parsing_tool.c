/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tool.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 22:29:02 by margot            #+#    #+#             */
/*   Updated: 2022/11/25 16:55:12 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_parsing_values_tool set_parsing_values_tool(t_parsing_values_tool values)
{
	values.origin = create_tuple(0, 0, 0, 1);
	values.ratio = 0.0;
	values.orientation_vector = create_tuple(0, 0, 0, 0);
	values.fov = 0.0;
	values.radius = 0.0;
	values.height = 0.0;
	values.color = create_color(0, 0, 0);
	return (values);
}

void	set_parsing_tool(t_parsing_tool *tool, int i, int ret)
{
	tool->i = i;
	tool->ret = ret;
}

t_parsing_tool	*init_parsing_tool()
{
	t_parsing_tool *tool;

	tool = malloc(sizeof(t_parsing_tool));
	if (!tool)
		return (NULL);
	tool->i = 0;
	tool->ret = NO_ERR;
	return (tool);
}
