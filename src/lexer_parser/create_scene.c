/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 22:26:42 by mpourrey          #+#    #+#             */
/*   Updated: 2022/11/18 23:07:16 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	get_parsing_value(int i, char *line)
{
	int		len;
	char	*p_value;
	int		j;
	
	len = 0;
	while (!ft_is_space(line[i + len]))
		len++;
	p_value = malloc(sizeof(char) * len + 1);
	j = 0;
	while (j < len)
	{
		p_value[j] = line[i + j];
		j++;	
	}
	p_value[j] == '\0';
	return (p_value);
}

int	parse_sphere(t_data *data, char *line)
{
	t_tuple	origin;
	int		value;
	char	*parsing_value;
	int		radius;
	int		i;

	i = 2;
	while (line[i] && ft_is_space(line[i]))
		i++;
	parsing_value = get_parsing_value(i + 1, line);
	//atof parsing_value
	//recup en tant que x/radius etc
	
	
	
	
	create_sphere(data, origin, radius);
}

int	parse_camera(t_data *data, char *line)
{
	int 	hsize;
	int		vsize;
	double	fov;

	
	create_camera(data, hsize, vsize, fov);
}

int	create_scene(t_data *data, t_list *lst)
{
	while (lst)
	{
		if (((char *)lst->content)[0] == 'C')
			parse_camera(data, (char *)lst->content);
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
