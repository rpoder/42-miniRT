/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tool.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 22:29:02 by margot            #+#    #+#             */
/*   Updated: 2022/11/30 22:08:25 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_parsing_tool	*set_parsing_tool(t_parsing_tool *tool)
{
	tool->i = 0;
	tool->error = NO_ERR;
	tool->str_value = NULL;
	tool->count = 0;
	return (tool);
}

t_parsing_tool	*init_parsing_tool(void)
{
	t_parsing_tool	*tool;

	tool = malloc(sizeof(t_parsing_tool));
	if (!tool)
		return (NULL);
	tool->i = 0;
	tool->error = NO_ERR;
	tool->str_value = NULL;
	tool->count = 0;
	return (tool);
}
