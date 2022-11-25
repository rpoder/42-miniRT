/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:07:27 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/25 18:46:26 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_is_space(line[i]))
		i++;
	if (line[i] && line[i] != '\n')
		return (false);
	return (true);
}

static t_list	*lexer(int fd) //si erreur de malloc free toute la liste
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
			{
				ft_lstclear(&alst, free);
				return (NULL);
			}
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
	if (file[len - 3] != '.' || file[len - 2] != 'r' || file[len - 1] != 't')
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
	int				fd;
	t_list			*parsing_lst;
	t_parsing_tool	*tool;
	int				ret;

	fd = open_file(file);
	if (fd == -1)
		return (PARSING_ERR);
	parsing_lst = lexer(fd);
	if (!parsing_lst)
		return (MALLOC_ERR);
	tool = init_parsing_tool();
	if (!tool)
	{
		ft_lstclear(&parsing_lst, free);
		return (MALLOC_ERR);
	}
	create_scene(data, parsing_lst, tool);
	if (tool->ret != NO_ERR)
	{
		ft_lstclear(&parsing_lst, free);
		ret = tool->ret;
		free(tool);
		return (ret);
	}
	ft_lstclear(&parsing_lst, free);
	free(tool);
	return (NO_ERR);
}
