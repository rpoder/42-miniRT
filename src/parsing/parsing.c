/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:07:27 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/16 14:18:53 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	open_file(char *file)
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

bool	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_is_space(line[i]))
		i++;
	if (line[i])
		return (true);
	return (false);
}

t_list	*lexer(int fd)
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

// int	check_file(int fd)
// {

// }

int	create_scene(t_data *data, t_list *lst)
{
	while (lst)
	{
		if (((char *)lst->content)[0] == 'C')
			parse_camera(data, );
		else if (((char *)lst->content)[0] == 'A')
			parse_ambient_light();
		else if (((char *)lst->content)[0] == 'L')
			parse_light();
		else if (((char *)lst->content)[0] == 's' && ((char *)lst->content)[1] == 'p')
			parse_sphere();
		else if (((char *)lst->content)[0] == 'p' && ((char *)lst->content)[1] == 'l')
			parse_plane();
		else if (((char *)lst->content)[0] == 'c' && ((char *)lst->content)[1] == 'y')
			parse_cylinder();
		lst = lst->next;
	}
}
