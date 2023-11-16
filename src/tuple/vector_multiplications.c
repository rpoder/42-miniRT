/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_multiplications.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:54:11 by mpourrey          #+#    #+#             */
/*   Updated: 2022/11/30 16:54:18 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	multiply_tuple_by_matrix(t_tuple tuple, t_matrix4 m)
{
	t_tuple	new_tuple;

	new_tuple.x = (tuple.x * m.matrix[0][0]) + (tuple.x * m.matrix[1][0])
		+ (tuple.x * m.matrix[2][0]) + (tuple.x * m.matrix[3][0]);
	new_tuple.y = (tuple.y * m.matrix[0][1]) + (tuple.y * m.matrix[1][1])
		+ (tuple.y * m.matrix[2][1]) + (tuple.y * m.matrix[3][1]);
	new_tuple.z = (tuple.z * m.matrix[0][2]) + (tuple.z * m.matrix[1][2])
		+ (tuple.z * m.matrix[2][2]) + (tuple.z * m.matrix[3][2]);
	new_tuple.w = tuple.w;
	return (new_tuple);
}

t_tuple	multiply_matrix_by_tuple(t_matrix4 m, t_tuple tuple)
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

t_tuple	multiply_tuple_by_double(t_tuple tuple, double c)
{
	t_tuple	new_tuple;

	new_tuple.x = tuple.x * c;
	new_tuple.y = tuple.y * c;
	new_tuple.z = tuple.z * c;
	new_tuple.w = tuple.w;
	return (new_tuple);
}
