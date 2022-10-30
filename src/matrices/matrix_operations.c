/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:52:46 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/30 13:39:15 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix4	ft_transpose_matrix(t_matrix4 m4)
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
			new_matrix.matrix[i][j] = m4.matrix[j][i];
			i++;
		}
		j++;
	}
	return (new_matrix);
}

t_matrix4	ft_multiply_matrices(t_matrix4 m4_1, t_matrix4 m4_2)
{
	t_matrix4	new_matrix;
	int			i;
	int			j;
	int			k;
	double		sum;

	j = 0;
	while(j < 4)
	{
		i = 0;
		while(i < 4)
		{
			k = 0;
			sum = 0;
			while (k < 4)
			{
				sum += m4_1.matrix[j][k] * m4_2.matrix[k][i];
				k++;
			}
			new_matrix.matrix[j][i] = sum;
			i++;
		}
		j++;
	}
	return (new_matrix);
}

t_matrix4	ft_inverse_matrix(t_matrix4 m)
{
	t_matrix4	new_m;
	double		determinant;

	determinant = compute_m4_determinant(m);
	if (is_matrix_invertible(m) == false)
	{
		ft_printf("m is not invertible\n");
		return (m);
	}
	new_m = apply_cofactors_to_matrix(m);
	new_m = ft_transpose_matrix(new_m);
	new_m = apply_determinant_division_to_matrix(new_m, determinant);

	return (new_m);
}
