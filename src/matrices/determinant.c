/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determinant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:50:14 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/30 15:23:23 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	compute_m2_determinant(t_matrix2 m2)
{
	return ((m2.matrix[0][0] * m2.matrix[1][1])
		- (m2.matrix[0][1] * m2.matrix[1][0]));
}

double	compute_m3_determinant(t_matrix3 m3)
{
	int		i;
	double	cofactor;
	double	sum;

	i = 0;
	sum = 0;
	while (i < 3)
	{
		cofactor = compute_m3_cofactor(m3, i, 0);
		sum += m3.matrix[0][i] * cofactor;
		i++;
	}
	return (sum);
}

double	compute_m4_determinant(t_matrix4 m4)
{
	int			i;
	double		cofactor;
	double		sum;

	i = 0;
	sum = 0;
	while (i < 4)
	{
		cofactor = compute_m4_cofactor(m4, i, 0);
		sum += m4.matrix[0][i] * cofactor;
		i++;
	}
	return (sum);
}

t_matrix4	apply_determinant_division_to_matrix(t_matrix4 m, double det)
{
	t_matrix4	new_m;
	int			i;
	int			j;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			new_m.matrix[j][i] = m.matrix[j][i] / det;
			i++;
		}
		j++;
	}
	return (new_m);
}
