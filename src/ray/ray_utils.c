/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 12:27:59 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/30 12:05:15 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	ft_create_ray(t_tuple origin, t_tuple direction)
{
	t_ray	new_ray;

	new_ray.origin = origin;
	new_ray.direction = direction;
	return (new_ray);
}

t_tuple	ft_calculate_new_point_on_ray(t_ray ray, double t)
{
	t_tuple	new_tuple;
	t_tuple	tmp;

	tmp = ft_multiply_tuple_by_double(ray.direction, t);
	new_tuple = ft_add_tuples(ray.origin, tmp);
	return (new_tuple);
}

t_intersections	calculate_sphere_intersections(double discr, t_double3 values)
{
	t_intersections	intersections;

	intersections = init_intersections();
	intersections.object = NULL;
	if (discr < 0)
	{
		intersections.nb_of_intersections = 0;
	}
	if (discr == 0)
	{
		intersections.nb_of_intersections = 1;
		intersections.i1 = (- values.b - sqrtf(discr)) / (2 * values.a);
		intersections.i2 = (- values.b + sqrtf(discr)) / (2 * values.a);
	}
	else if (discr > 0)
	{
		intersections.nb_of_intersections = 2;
		intersections.i1 = (- values.b - sqrtf(discr)) / (2 * values.a);
		intersections.i2 = (- values.b + sqrtf(discr)) / (2 * values.a);
	}
	return (intersections);
}

t_intersections	ft_get_sphere_intersections(t_object *sphere, t_ray ray)
{
	double					discriminant;
	t_tuple					sphere_to_ray;
	t_tuple					w_origin;
	t_double3				values;
	t_ray					ray2;

	ray2 = transform_ray_by_matrix(ray, ft_inverse_matrix(sphere->transform_m));
	w_origin = ft_create_tuple(0, 0, 0, 1);
	sphere_to_ray = ft_sub_tuples(ray2.origin, w_origin);
	values.a = ft_tuple_scalarproduct(ray2.direction, ray2.direction);
	values.b = 2 * ft_tuple_scalarproduct(ray2.direction, sphere_to_ray);
	values.c = ft_tuple_scalarproduct(sphere_to_ray, sphere_to_ray) - 1;
	discriminant = powf(values.b, 2) - (4 * values.a * values.c);
	return (calculate_sphere_intersections(discriminant, values));
}

t_intersections	init_intersections(void)
{
	t_intersections	new_intersections;

	new_intersections.nb_of_intersections = 0;
	new_intersections.object = NULL;
	new_intersections.i1 = 0;
	new_intersections.i2 = 0;
	return (new_intersections);
}

t_ray	transform_ray_by_matrix(t_ray ray, t_matrix4 m)
{
	t_ray	new_ray;

	new_ray.origin = ft_multiply_matrix_by_tuple(m, ray.origin);
	new_ray.direction = ft_multiply_matrix_by_tuple(m, ray.direction);
	return (new_ray);
}
