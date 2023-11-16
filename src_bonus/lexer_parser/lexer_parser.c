/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:07:27 by rpoder            #+#    #+#             */
/*   Updated: 2022/12/01 01:18:47 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	create_node_with_line(int *ret_gnl, char *line, t_list **alst,
	int fd)
{
	t_list	*node;

	if (!is_empty_line(line))
	{
		node = ft_lstnew(line);
		if (!node)
			return (handle_gnl_error(ret_gnl, line, alst, fd), MALLOC_ERR);
		ft_lstadd_back(alst, node);
	}
	else
		free(line);
	return (NO_ERR);
}

static t_list	*lexer(int fd)
{
	t_list	*alst;
	int		ret_node;
	char	*line;
	int		*ret_gnl;

	ret_gnl = malloc(sizeof(int));
	if (!ret_gnl)
		return (NULL);
	*ret_gnl = NO_ERR;
	line = get_next_line(fd, ret_gnl);
	alst = NULL;
	if (*ret_gnl == GNL_MALLOC_ERR)
		return (handle_gnl_error(ret_gnl, NULL, &alst, fd), NULL);
	while (line)
	{
		ret_node = create_node_with_line(ret_gnl, line, &alst, fd);
		if (ret_node != NO_ERR)
			return (NULL);
		line = get_next_line(fd, ret_gnl);
		if (*ret_gnl == GNL_MALLOC_ERR)
			return (handle_gnl_error(ret_gnl, line, &alst, fd), NULL);
	}
	free(ret_gnl);
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
		ft_putstr_fd("ERR:	Your scene.rt ought to be an existing file.\n", 2);
		return (-1);
	}
	return (fd);
}

void	lexer_parser(t_data *data, char *file)
{
	int		fd;
	t_list	*parsing_lst;
	int		ret;

	fd = open_file(file);
	if (fd == -1)
		global_free(data, PARSING_ERR);
	parsing_lst = lexer(fd);
	close(fd);
	if (!parsing_lst)
		global_free(data, MALLOC_ERR);
	ret = parse_scene(data, parsing_lst);
	ft_lstclear(&parsing_lst, free);
	if (ret != NO_ERR)
		global_free(data, ret);
}
