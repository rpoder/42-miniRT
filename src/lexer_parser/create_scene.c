/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margot <margot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 22:26:42 by mpourrey          #+#    #+#             */
/*   Updated: 2022/11/21 20:06:28 by margot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	get_parsing_value(int i, char *line)
{
	int		len;
	char	*p_value;
	int		j;
	
	len = 0;
	while (!ft_is_space(line[i + len]) && line[i + len] != ',')
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

t_tuple get_coordinates(char *line, int ret)
{
	int		i;
	int		count;
	char	*str_value;
	double	double_value;
	double	coordinates[3];
	
	i = 2;
	count = 0;
	while (count < 3)
	{
		while (line[i] && ft_is_space(line[i]))
			i++;
		str_value = get_parsing_value(i + 1, line);
		if (ft_atof_checker(str_value) != 1)
		{
			printf("ERR : %s in your scene.rt is not a valid value\n", str_value);
			ret = PARSING_ERR;
			return (create_tuple(0, 0, 0, 0));
		}
		coordinates[count] = ft_atof(str_value);
		count++;
		if (count < 2)
		{
			while (line[i] && line[i] != ',')
				i++;
		}
	}
	return(create_tuple(coordinates[0], coordinates[1], coordinates[2], 1));
}

int	parse_sphere(t_data *data, char *line)
{
	t_tuple	origin;
	int		radius;
	int		ret;

	origin = get_coordinates(line, ret);
	if (ret != NO_ERR)
		return (ret);
	
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
