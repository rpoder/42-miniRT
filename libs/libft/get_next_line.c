/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:49:04 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/16 11:57:25 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*trim_line(char *str)
{
	int		len;
	int		i;
	char	*dst;

	len = 0;
	i = 0;
	while(str[len] && str[len] != '\n')
		len++;
	if (str[len] == '\n')
		len++;
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	while (i < len)
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static char	*trim_rest(char *str)
{
	int		len;
	int		i;
	char	*dst;

	len = 0;
	i = 0;
	while(str[len] && str[len] != '\n')
		len++;
	if (str[len] == '\n')
		len++;
	dst = malloc(sizeof(char) * (ft_strlen(str + len) + 1));
	if (!dst)
		return (NULL);
	while (str[len])
	{
		dst[i] = str[len];
		i++;
		len++;
	}
	dst[i] = '\0';
	return (dst);
}

static char	*read_line(int fd, char *rest)
{
	char	*buf;
	int		ret;

	ret = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (ret > 0 && !ft_gnl_strrchr(rest, '\n'))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret <= 0)
		{
			if (rest)
				free(rest);
			free(buf);
			return (NULL);
		}
		buf[ret] = '\0';
		rest = ft_gnl_strjoin(rest, buf);
		if (!rest)
		{
			free(buf);
			return (NULL);
		}
	}
	free(buf);
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffed_line;
	static char	*rest = NULL;

	if (fd < 0)
		return (NULL);
	buffed_line = read_line(fd, rest);
	if (!buffed_line)
	{
		free(buffed_line);
		return (NULL);
	}
	line = trim_line(buffed_line);
	if (!line)
		return (NULL);
	rest = trim_rest(buffed_line);
	if (!rest)
		return (NULL);
	free(buffed_line);
	return (line);
}
