/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tool.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 22:29:02 by margot            #+#    #+#             */
/*   Updated: 2022/11/26 20:23:32 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_parsing_tool(t_parsing_tool *tool, int i, int ret)
{
	tool->i = i;
	tool->error = ret;
}

t_parsing_tool	*init_parsing_tool()
{
	t_parsing_tool *tool;

	tool = malloc(sizeof(t_parsing_tool)); //proteger
	if (!tool)
		return (NULL);
	tool->i = 0;
	tool->error = NO_ERR;
	return (tool);
}
