/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 12:27:59 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/30 17:52:17 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	create_ray(t_tuple origin, t_tuple direction)
{
	t_ray	new_ray;

	new_ray.origin = origin;
	new_ray.direction = direction;
	return (new_ray);
}

t_tuple	compute_new_point_on_normalized_ray(t_ray ray, double t)
{
	t_tuple	new_tuple;
	t_tuple	tmp;

	tmp = multiply_tuple_by_double(ray.direction, t);
	new_tuple = add_tuples(ray.origin, tmp);
	new_tuple = normalize_tuple(new_tuple);
	return (new_tuple);
}

t_tuple	compute_new_point_on_ray(t_ray ray, double t)
{
	t_tuple	new_tuple;
	t_tuple	tmp;

	tmp = multiply_tuple_by_double(ray.direction, t);
	new_tuple = add_tuples(ray.origin, tmp);
	return (new_tuple);
}

t_ray	transform_ray_by_matrix(t_ray ray, t_matrix4 m)
{
	t_ray	new_ray;

	new_ray.origin = multiply_matrix_by_tuple(m, ray.origin);
	new_ray.direction = multiply_matrix_by_tuple(m, ray.direction);
	return (new_ray);
}
