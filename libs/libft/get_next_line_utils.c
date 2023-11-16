/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:51:07 by rpoder            #+#    #+#             */
/*   Updated: 2022/12/01 00:37:34 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_gnl_strrchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			return (true);
		i++;
	}
	return (false);
}

static t_int3	init_counter(void)
{
	t_int3	counter;

	counter.i = 0;
	counter.j = 0;
	counter.k = 0;
	return (counter);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	t_int3	counter;
	char	*dst;

	counter = init_counter();
	if (!s1 && !s2)
		return (NULL);
	dst = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dst)
		return (NULL);
	while (s1 && s1[counter.j])
	{
		dst[counter.i] = s1[counter.j];
		counter.i++;
		counter.j++;
	}
	if (s1)
		free(s1);
	while (s2 && s2[counter.k])
	{
		dst[counter.i] = s2[counter.k];
		counter.i++;
		counter.k++;
	}
	dst[counter.i] = '\0';
	return (dst);
}
