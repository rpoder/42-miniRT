/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cofactor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 13:34:29 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/30 15:26:49 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	compute_m3_cofactor(t_matrix3 m3, int i, int j)
{
	double		cofactor;
	t_matrix2	sub_m2;
	double		minor;

	sub_m2 = sub_m3tom2(m3, j, i);
	minor = compute_m2_determinant(sub_m2);
	if ((i + j) % 2 != 0)
		cofactor = minor * -1;
	else
		cofactor = minor;
	return (cofactor);
}

double	compute_m4_cofactor(t_matrix4 m4, int i, int j)
{
	double		cofactor;
	t_matrix3	sub_m3;
	double		minor;

	sub_m3 = sub_m4tom3(m4, j, i);
	minor = compute_m3_determinant(sub_m3);
	if ((i + j) % 2 != 0)
		cofactor = minor * -1;
	else
		cofactor = minor;
	return (cofactor);
}

t_matrix4	apply_cofactors_to_matrix(t_matrix4 m)
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
			new_m.matrix[j][i] = compute_m4_cofactor(m, i, j);
			i++;
		}
		j++;
	}
	return (new_m);
}
