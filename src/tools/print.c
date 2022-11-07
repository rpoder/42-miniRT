/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:46:08 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/07 17:50:14 by rpoder           ###   ########.fr       */
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
	printf("\n");
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
	printf("\n");
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

void	ft_print_ray(t_ray ray)
{
	ft_print_tuple("ray.origin", ray.origin);
	ft_print_tuple("ray.direction", ray.direction);
}

void	ft_print_intersection(t_intersections intersections)
{
	printf("intersection.nb = %d\n", intersections.nb_of_intersections);
	printf("intersection.i1 = %d\n", intersections.nb_of_intersections);
	printf("intersection.i2 = %d\n", intersections.nb_of_intersections);
	printf("intersection.objectId = %d\n\n", intersections.object->id);
}

void	print_bits_of_long(long num)
{
	unsigned int size = sizeof(int);
	unsigned int maxPow = 1 <<(size * 8 - 1);

	printf("MAX POW : %u\n",maxPow);
	int i=0,j;
	for(;i < size * 8; ++i)
	{
		printf("%u ",num&maxPow ? 1 : 0);
		num = num << 1;
	}
}
