/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_parser_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 23:28:45 by rpoder            #+#    #+#             */
/*   Updated: 2022/12/01 01:10:57 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	handle_gnl_error(int *ret_gnl, char *line, t_list **alst, int fd)
{
	*ret_gnl = GNL_MALLOC_ERR;
	get_next_line(fd, ret_gnl);
	close(fd);
	free(ret_gnl);
	if (line)
		free(line);
	if (alst)
		ft_lstclear(alst, free);
}

bool	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_is_space(line[i]))
		i++;
	if (line[i])
		return (false);
	return (true);
}
