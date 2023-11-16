/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_objects_checker.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:33:04 by rpoder            #+#    #+#             */
/*   Updated: 2022/12/02 01:48:20 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_check_p_tool	init_check_p_tool(void)
{
	t_check_p_tool	tool;

	tool.camera = 0;
	tool.ambient = 0;
	tool.lights = 0;
	tool.objects = 0;
	return (tool);
}

static t_check_p_tool	count_parsing_objects(t_list *lst, t_check_p_tool tool)
{
	char	*line;

	while (lst)
	{
		line = (char *)lst->content;
		if (line[0] == 'c' || line[0] == 's' || line[0] == 'p'
			|| line[0] == 't')
		{
			tool.objects++;
			if (tool.objects > INT_MAX)
				break ;
		}
		else if (line[0] == 'A')
			tool.ambient++;
		else if (line[0] == 'L')
		{
			tool.lights++;
			if (tool.lights > INT_MAX)
				break ;
		}
		else if (line[0] == 'C')
			tool.camera++;
		lst = lst->next;
	}
	return (tool);
}

int	check_scene_is_complete(t_list *lst)
{
	t_check_p_tool	tool;

	tool = init_check_p_tool();
	tool = count_parsing_objects(lst, tool);
	if (tool.camera != 1 || tool.ambient != 1 || tool.lights < 1
		|| tool.lights != 1 || tool.objects < 1 || tool.objects > INT_MAX)
	{
		ft_putstr_fd("Error\nERR :	 ", 2);
		ft_putstr_fd("Your scene.rt must contain one camera, one", 2);
		ft_putstr_fd(" ambient light, one point light and", 2);
		ft_putstr_fd(" at least one object.\n", 2);
		return (PARSING_ERR);
	}
	return (NO_ERR);
}
