/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:05:12 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/27 23:16:10 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	ft_add_tuples(t_tuple a, t_tuple b)
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
