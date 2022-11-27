/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:50:28 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/27 18:13:14 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	ft_normalize_tuple(t_tuple a)
{
	double	len;
	t_tuple	new_tuple;

	len = ft_tuple_len(a);
	new_tuple.x = a.x / len;
	new_tuple.y = a.y / len;
	new_tuple.z = a.z / len;
	new_tuple.w = a.w;
	return (new_tuple);
}

double	ft_tuple_scalarproduct(t_tuple a, t_tuple b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

t_tuple	ft_multiply_tuples(t_tuple a, t_tuple b)
{
	t_tuple	new_tuple;

	new_tuple.x = (a.y * b.z) - (a.z * b.y);
	new_tuple.y = (a.z * b.x) - (a.x * b.z);
	new_tuple.z = (a.x * b.y) - (a.y * b.x);
	new_tuple.w = a.w; // ??
	return (new_tuple);
}

t_tuple	ft_multiply_tuple_by_matrix(t_tuple tuple, t_matrix4 m)
{
	t_tuple	new_tuple;

	new_tuple.x = (tuple.x * m.matrix[0][0]) +  (tuple.x * m.matrix[1][0])
		+ (tuple.x * m.matrix[2][0]) +  (tuple.x * m.matrix[3][0]);
	new_tuple.y = (tuple.y * m.matrix[0][1]) +  (tuple.y * m.matrix[1][1])
		+ (tuple.y * m.matrix[2][1]) +  (tuple.y * m.matrix[3][1]);
	new_tuple.z = (tuple.z * m.matrix[0][2]) +  (tuple.z * m.matrix[1][2])
		+ (tuple.z * m.matrix[2][2]) +  (tuple.z * m.matrix[3][2]);
	new_tuple.w = tuple.w;

	return (new_tuple);
}

t_tuple	ft_multiply_matrix_by_tuple(t_matrix4 m, t_tuple tuple)
{
	t_tuple	new_tuple;

	new_tuple.x = (m.matrix[0][0] * tuple.x) + (m.matrix[0][1] * tuple.y)
		+ (m.matrix[0][2] * tuple.z) + (m.matrix[0][3] * tuple.w);
	new_tuple.y = (m.matrix[1][0] * tuple.x) + (m.matrix[1][1] * tuple.y)
		+ (m.matrix[1][2] * tuple.z) + (m.matrix[1][3] * tuple.w);
	new_tuple.z = (m.matrix[2][0] * tuple.x) + (m.matrix[2][1] * tuple.y)
		+ (m.matrix[2][2] * tuple.z) + (m.matrix[2][3] * tuple.w);
	new_tuple.w = tuple.w;

	return (new_tuple);
}

t_tuple	ft_multiply_tuple_by_double(t_tuple tuple, double c)
{
	t_tuple	new_tuple;

	new_tuple.x = tuple.x * c;
	new_tuple.y = tuple.y * c;
	new_tuple.z = tuple.z * c;
	new_tuple.w = tuple.w;
	return (new_tuple);
}
