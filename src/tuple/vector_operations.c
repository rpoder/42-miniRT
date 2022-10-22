/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:05:12 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/19 15:23:26 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	ft_create_tuple(float x, float y, float z, float w)
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
t_tuple	ft_scale_tuple(t_tuple a, float scale)
{
	t_tuple	new_tuple;

	new_tuple.x = a.x * scale;
	new_tuple.y = a.y * scale;
	new_tuple.z = a.z * scale;
	new_tuple.w = a.w;
	return (new_tuple);
}

// faut-il checker si seulement vecteur ???
float	ft_tuple_len(t_tuple a)
{
	float	len;

	len = sqrtf(powf(a.x, 2) + powf(a.y, 2) + powf(a.z, 2));
	return (len);
}

t_tuple	ft_normalize_tuple(t_tuple a)
{
	float	len;
	t_tuple	new_tuple;

	len = ft_tuple_len(a);
	new_tuple.x = a.x / len;
	new_tuple.y = a.y / len;
	new_tuple.z = a.z / len;
	new_tuple.w = a.w;
	return (new_tuple);
}

float	ft_tuple_scalarproduct(t_tuple a, t_tuple b)
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
