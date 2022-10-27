/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse_matrix_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:50:14 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/27 13:13:45 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"



double	ft_calculate_m2_determinant(t_matrix2 m2)
{
	return ((m2.matrix[0][0] * m2.matrix[1][1])
		- (m2.matrix[0][1] * m2.matrix[1][0]));
}


double	ft_calculate_m3_determinant(t_matrix3 m3)
{
	int		i;
	double	cofactor;
	double	sum;

	i = 0;
	sum = 0;
	while (i < 3)
	{
		cofactor = ft_calculate_m3_cofactor(m3, i, 0);
		sum += m3.matrix[0][i] * cofactor;
		i++;
	}
	return (sum);
}

double	ft_calculate_m4_determinant(t_matrix4 m4)
{
	int			i;
	double		cofactor;
	double		sum;

	i = 0;
	sum = 0;
	while (i < 4)
	{
		cofactor = ft_calculate_m4_cofactor(m4, i, 0);
		sum += m4.matrix[0][i] * cofactor;
		i++;
	}
	return (sum);
}

double	ft_calculate_m3_cofactor(t_matrix3 m3, int i, int j)
{
	double	cofactor;
	t_matrix2	sub_m2;
	double		minor;

	sub_m2 = ft_sub_m3tom2(m3, j, i);
	minor = ft_calculate_m2_determinant(sub_m2);
	if ((i + j) % 2 != 0)
		cofactor = minor * -1;
	else
		cofactor = minor;
	return (cofactor);
}

double	ft_calculate_m4_cofactor(t_matrix4 m4, int i, int j)
{
	double		cofactor;
	t_matrix3	sub_m3;
	double		minor;

	sub_m3 = ft_sub_m4tom3(m4, j, i);
	minor = ft_calculate_m3_determinant(sub_m3);
	if ((i + j) % 2 != 0)
		cofactor = minor * -1;
	else
		cofactor = minor;
	return (cofactor);
}
