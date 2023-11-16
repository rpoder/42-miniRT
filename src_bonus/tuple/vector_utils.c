/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:50:28 by rpoder            #+#    #+#             */
/*   Updated: 2022/12/02 17:44:21 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	normalize_tuple(t_tuple a)
{
	double	len;
	t_tuple	new_tuple;

	len = tuple_len(a);
	new_tuple.x = a.x / len;
	new_tuple.y = a.y / len;
	new_tuple.z = a.z / len;
	new_tuple.w = a.w;
	return (new_tuple);
}

double	dot_product(t_tuple a, t_tuple b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

double	tuple_len(t_tuple a)
{
	double	len;

	len = sqrtf(powf(a.x, 2) + powf(a.y, 2) + powf(a.z, 2));
	return (len);
}
