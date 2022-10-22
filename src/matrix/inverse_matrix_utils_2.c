/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse_matrix_utils_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:03:40 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/21 18:06:06 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	ft_is_matrix_invertible(t_matrix4 m)
{
	float	determinant;

	determinant = ft_calculate_m4_determinant(m);
	if (determinant == 0)
		return (false);
	return (true);
}

t_matrix4	ft_apply_cofactors_to_matrix(t_matrix4 m)
{
	t_matrix4	new_m;
	int			i;
	int			j;
	j = 0;
	while(j < 4)
	{
		i = 0;
		while(i < 4)
		{
			new_m.matrix[j][i] = ft_calculate_m4_cofactor(m, i, j);
			i++;
		}
		j++;
	}
	return (new_m);
}

t_matrix4	ft_apply_determinant_division_to_matrix(t_matrix4 m, float det)
{
	t_matrix4	new_m;
	int			i;
	int			j;

	j = 0;
	while(j < 4)
	{
		i = 0;
		while(i < 4)
		{
			new_m.matrix[j][i] = m.matrix[j][i] / det;
			i++;
		}
		j++;
	}
	return (new_m);
}
