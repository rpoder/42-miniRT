/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_normal_and_intersections.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:01:36 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/28 00:12:03 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	get_sphere_normal_at(t_object *sphere, t_tuple object_point)
{
	t_tuple	origin;
	t_tuple	object_normal;

	origin = create_tuple(0, 0, 0, 1);
	object_normal = sub_tuples(object_point, origin);
	return (object_normal);
}

static t_intersections	compute_sphere_intersections(t_object *object, double discr, t_double3 values)
{
	t_intersections	intersections;

	intersections = init_intersections(object);
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

t_intersections	get_sphere_intersections(t_object *sphere, t_ray ray)
{
	double					discriminant;
	t_tuple					sphere_to_ray;
	t_tuple					w_origin;
	t_double3				values;

	w_origin = create_tuple(0, 0, 0, 1);
	sphere_to_ray = sub_tuples(ray.origin, w_origin);
	values.a = dot_product(ray.direction, ray.direction);
	values.b = 2 * dot_product(ray.direction, sphere_to_ray);
	values.c = dot_product(sphere_to_ray, sphere_to_ray) - 1;
	discriminant = powf(values.b, 2) - (4 * values.a * values.c);
	return (compute_sphere_intersections(sphere, discriminant, values));
}
