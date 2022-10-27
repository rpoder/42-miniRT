/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:05:12 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/27 15:01:57 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	ft_create_tuple(double x, double y, double z, double w)
{
	t_tuple	new_tuple;

	new_tuple.x = x;
	new_tuple.y = y;
	new_tuple.z = z;
	new_tuple.w = w;
	return (new_tuple);
}

t_tuple	ft_add_tuples(t_tuple a, t_tuple b)
{
	t_tuple	new_tuple;

	new_tuple.x = a.x + b.x;
	new_tuple.y = a.y + b.y;
	new_tuple.z = a.z + b.z;
	new_tuple.w = a.w + b.w;
	return (new_tuple);
}

t_tuple	ft_sub_tuples(t_tuple a, t_tuple b)
{
	t_tuple	new_tuple;

	new_tuple.x = a.x - b.x;
	new_tuple.y = a.y - b.y;
	new_tuple.z = a.z - b.z;
	new_tuple.w = a.w - b.w;
	return (new_tuple);
}

t_tuple	ft_neg_tuple(t_tuple a)
{
	t_tuple	new_tuple;

	new_tuple.x = -a.x;
	new_tuple.y = -a.y;
	new_tuple.z = -a.z;
	new_tuple.w = a.w;
	return (new_tuple);
}

// faut-il checker si seulement vecteur ???
t_tuple	ft_scale_tuple(t_tuple a, double scale)
{
	t_tuple	new_tuple;

	new_tuple.x = a.x * scale;
	new_tuple.y = a.y * scale;
	new_tuple.z = a.z * scale;
	new_tuple.w = a.w;
	return (new_tuple);
}

// faut-il checker si seulement vecteur ???
double	ft_tuple_len(t_tuple a)
{
	double	len;

	len = sqrtf(powf(a.x, 2) + powf(a.y, 2) + powf(a.z, 2));
	return (len);
}

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
