/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:46:08 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/21 12:07:24 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_print_tuple(char *tuple_name, t_tuple tuple)
{
	printf("%s(%f, %f, %f, %f)\n", tuple_name, tuple.x, tuple.y, tuple.z, tuple.w);
}

void	ft_print_color(char *color_name, t_color color)
{
	printf("%s(%f, %f, %f)\n", color_name, color.red, color.green, color.blue);
}

void	ft_print_matrix4(t_matrix4 m4)
{
	int			i;
	int			j;

	j = 0;
	while(j < 4)
	{
		i = 0;
		printf("|");
		while(i < 4)
		{
			printf("%f" ,m4.matrix[j][i]);
			if (i != 3)
			printf(", ");
			i++;
		}
		printf("|\n");
		j++;
	}
}

void	ft_print_matrix3(t_matrix3 m3)
{
	int			i;
	int			j;

	j = 0;
	while(j < 3)
	{
		i = 0;
		printf("|");
		while(i < 3)
		{
			printf("%f" ,m3.matrix[j][i]);
			if (i != 2)
			printf(", ");
			i++;
		}
		printf("|\n");
		j++;
	}
}

void	ft_print_matrix2(t_matrix2 m2)
{
	int			i;
	int			j;

	j = 0;
	while(j < 2)
	{
		i = 0;
		printf("|");
		while(i < 2)
		{
			printf("%f" ,m2.matrix[j][i]);
			if (i != 1)
			printf(", ");
			i++;
		}
		printf("|\n");
		j++;
	}
}
