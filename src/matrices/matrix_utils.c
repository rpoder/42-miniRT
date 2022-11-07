/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:04:59 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/07 11:44:06 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix4	m4_bzero(void)
{
	t_matrix4	new_matrix;
	int			i;
	int			j;

	j = 0;
	while(j < 4)
	{
		i = 0;
		while(i < 4)
		{
			new_matrix.matrix[i][j] = 0.0;
			i++;
		}
		j++;
	}
	return (new_matrix);
}

t_matrix4	get_identity_matrix(void)
{
	t_matrix4	identity_matrix;

	identity_matrix = m4_bzero();
	identity_matrix.matrix[0][0] = 1.0;
	identity_matrix.matrix[1][1] = 1.0;
	identity_matrix.matrix[2][2] = 1.0;
	identity_matrix.matrix[3][3] = 1.0;
	return (identity_matrix);
}

bool	is_matrix_invertible(t_matrix4 m)
{
	double	determinant;

	determinant = compute_m4_determinant(m);
	if (determinant == 0)
		return (false);
	return (true);
}
