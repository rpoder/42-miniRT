/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 22:26:42 by mpourrey          #+#    #+#             */
/*   Updated: 2022/11/26 19:50:24 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_scene(t_data *data, t_list *lst)
{
	int				ret;
	t_parsing_tool	*tool;

	tool = init_parsing_tool();
	if (!tool)
		return (MALLOC_ERR);
	while (lst)
	{
		if (((char *)lst->content)[0] == 'c' && ((char *)lst->content)[1] == 'u')
			ret = parse_cube(data, (char *)lst->content, tool);
		if (((char *)lst->content)[0] == 'c' && ((char *)lst->content)[1] == 'y')
			ret = parse_cylinder(data, (char *)lst->content, tool);
		else
			printf("No object match.\n");
		if (ret != NO_ERR)
			break ;
		lst = lst->next;
	}
	free(tool);
	return (ret);
}


