/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:52:46 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/21 13:48:46 by rpoder           ###   ########.fr       */
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

float	ft_calculate_m2_determinant(t_matrix2 m2)
{
	return ((m2.matrix[0][0] * m2.matrix[1][1])
		- (m2.matrix[0][1] * m2.matrix[1][0]));
}

float	ft_calculate_m3_determinant(t_matrix3 m3)
{
	int		i;
	float	cofactor;
	float	sum;

	i = 0;
	sum = 0;
	while (i < 3)
	{
		cofactor = ft_calculate_cofactor(m3, i, 0);
		sum += m3.matrix[0][i] * cofactor;
		i++;
	}
	return (sum);
}

float	ft_calculate_m4_determinant(t_matrix4 m4)
{
	int			i;
	float		sum;
	float		determinant;
	t_matrix3	sub_m3;

	i = 0;
	sum = 0;
	while (i < 4)
	{
		sub_m3 = ft_sub_m4tom3(m4, 0, i);
		determinant = ft_calculate_m3_determinant(sub_m3);
		if ((i + 0) % 2 != 0)
		{
			determinant = determinant * -1;
		}
		sum += m4.matrix[0][i] * determinant;
		i++;
	}
	return (sum);
}


float	ft_calculate_minor(t_matrix3 m3, int i, int j)
{
	t_matrix2	sub;
	float		minor;

	sub = ft_sub_m3tom2(m3, j, i);
	printf("\n");
	ft_print_matrix2(sub);
	minor = ft_calculate_m2_determinant(sub);
	printf("minor(A, %d, %d) = %f\n", i, j, minor);
	return (minor);
}

float	ft_calculate_cofactor(t_matrix3 m3, int i, int j)
{
	float	minor;
	float	cofactor;

	minor = ft_calculate_minor(m3, i, j);
	cofactor = minor;
	if ((i + j) % 2 != 0)
	{
		cofactor = cofactor * -1;
	}
	printf("cofactor(A, %d, %d) = %f\n", i, j, cofactor);
	return (cofactor);
}

t_matrix3	ft_sub_m4tom3(t_matrix4 m4, int row, int column)
{
	t_matrix3	new_m3;
	int			i;
	int			j;
	int			k;
	int			l;

	i = 0;
	k = 0;
	while(i < 4)
	{
		j = 0;
		l = 0;
		if (i != column)
		{
			while(j < 4)
			{
				if (j != row)
				{
					new_m3.matrix[l][k] = m4.matrix[j][i];
					l++;
				}
				j++;
			}
			k++;
		}
		i++;
	}
	return (new_m3);
}

t_matrix2	ft_sub_m3tom2(t_matrix3 m3, int row, int column)
{
	t_matrix2	new_m2;
	int			i;
	int			j;
	int			k;
	int			l;

	i = 0;
	k = 0;
	while(i < 3)
	{
		j = 0;
		l = 0;
		if (i != column)
		{
			while(j < 3)
			{
				if (j != row)
				{
					new_m2.matrix[l][k] = m3.matrix[j][i];
					l++;
				}
				j++;
			}
			k++;
		}
		i++;
	}
	return (new_m2);
}

