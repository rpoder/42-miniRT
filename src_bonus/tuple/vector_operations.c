/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:05:12 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/30 17:52:44 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	add_tuples(t_tuple a, t_tuple b)
{
	t_tuple	new_tuple;

	new_tuple.x = a.x + b.x;
	new_tuple.y = a.y + b.y;
	new_tuple.z = a.z + b.z;
	new_tuple.w = a.w + b.w;
	return (new_tuple);
}

t_tuple	sub_tuples(t_tuple a, t_tuple b)
{
	t_tuple	new_tuple;

	new_tuple.x = a.x - b.x;
	new_tuple.y = a.y - b.y;
	new_tuple.z = a.z - b.z;
	new_tuple.w = a.w - b.w;
	return (new_tuple);
}

t_tuple	neg_tuple(t_tuple a)
{
	t_tuple	new_tuple;

	new_tuple.x = -a.x;
	new_tuple.y = -a.y;
	new_tuple.z = -a.z;
	new_tuple.w = a.w;
	return (new_tuple);
}

t_tuple	scale_tuple(t_tuple a, double scale)
{
	t_tuple	new_tuple;

	new_tuple.x = a.x * scale;
	new_tuple.y = a.y * scale;
	new_tuple.z = a.z * scale;
	new_tuple.w = a.w;
	return (new_tuple);
}

t_tuple	cross_product(t_tuple a, t_tuple b)
{
	t_tuple	new_tuple;

	new_tuple.x = (a.y * b.z) - (a.z * b.y);
	new_tuple.y = (a.z * b.x) - (a.x * b.z);
	new_tuple.z = (a.x * b.y) - (a.y * b.x);
	new_tuple.w = a.w;
	return (new_tuple);
}
