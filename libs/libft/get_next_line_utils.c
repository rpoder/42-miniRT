/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:51:07 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/16 11:52:42 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_gnl_strrchr(char *str, char c)
{
	int	i;

	i = 0;
	while(str && str[i])
	{
		if (str[i] == c)
			return (true);
		i++;
	}
	return (false);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		k;
	char	*dst;

	i = 0;
	j = 0;
	k = 0;
	if (!s1 && !s2)
		return (NULL);
	dst = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dst)
		return (NULL);
	while (s1 && s1[j])
	{
		dst[i] = s1[j];
		i++;
		j++;
	}
	if (s1)
		free(s1);
	while (s2 && s2[k])
	{
		dst[i] = s2[k];
		i++;
		k++;
	}
	dst[i] = '\0';
	return (dst);
}
