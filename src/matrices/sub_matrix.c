/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:58:28 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/30 15:26:10 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix3	sub_m4tom3(t_matrix4 m4, int row, int column)
{
	t_matrix3	new_m3;
	t_counter4	counter;

	counter = init_counter4();
	while (counter.i < 4)
	{
		counter.j = 0;
		counter.l = 0;
		if (counter.i != column)
		{
			while (counter.j < 4)
			{
				if (counter.j != row)
				{
					new_m3.matrix[counter.l][counter.k]
						= m4.matrix[counter.j][counter.i];
					counter.l++;
				}
				counter.j++;
			}
			counter.k++;
		}
		counter.i++;
	}
	return (new_m3);
}

t_matrix2	sub_m3tom2(t_matrix3 m3, int row, int column)
{
	t_matrix2	new_m2;
	t_counter4	counter;

	counter = init_counter4();
	while (counter.i < 3)
	{
		counter.j = 0;
		counter.l = 0;
		if (counter.i != column)
		{
			while (counter.j < 3)
			{
				if (counter.j != row)
				{
					new_m2.matrix[counter.l][counter.k]
						= m3.matrix[counter.j][counter.i];
					counter.l++;
				}
				counter.j++;
			}
			counter.k++;
		}
		counter.i++;
	}
	return (new_m2);
}
