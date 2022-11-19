/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:07:27 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/18 22:28:46 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_is_space(line[i]))
		i++;
	if (line[i])
		return (true);
	return (false);
}

static t_list	*lexer(int fd)
{
	t_list	*alst;
	t_list	*node;
	char	*line;

	line = get_next_line(fd); ////////////////
	alst = NULL;
	while (line)
	{
		if (!is_empty_line(line))
		{
			node = ft_lstnew(line);
			if (!node)
				return (NULL);
			ft_lstadd_back(&alst, node);
		}
		line = get_next_line(fd); /////////////
	}
	close (fd);
	return (alst);
}

static int	open_file(char *file)
{
	int	fd;
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(file);
	if (file[len - 2] != '.' || file[len - 1] != 'r' || file[len] != 't')
	{
		ft_putstr_fd("ERR:	Your scene file ought to end with '.rt'.\n", 2);
		return (-1);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("ERR:	Your scene.rt ought to be a file.\n", 2);
		return (-1);
	}
	return (fd);
}

int	lexer_parser(t_data *data, char *file)
{
	int		fd;
	t_list	*objects_lst;

	fd = open_file(file);
	if (fd == -1)
		return (-1);
	objects_lst = lexer(fd);
	if (!objects_lst)
		return (-1);
	return (0);
	create_scene(data, objects_lst);
}
