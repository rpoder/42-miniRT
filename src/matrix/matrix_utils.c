/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:04:59 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/21 18:05:24 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix4	ft_get_identity_matrix(void)
{
	t_matrix4	identity_matrix;

	identity_matrix = ft_create_matrix();
	identity_matrix.matrix[0][0] = 1.0;
	identity_matrix.matrix[1][1] = 1.0;
	identity_matrix.matrix[2][2] = 1.0;
	identity_matrix.matrix[3][3] = 1.0;
	return (identity_matrix);
}

t_matrix4	ft_create_matrix(void)
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
