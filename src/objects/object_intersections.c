/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_intersections.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margot <margot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:48:27 by margot            #+#    #+#             */
/*   Updated: 2022/11/03 16:52:34 by margot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_intersections	init_intersections(t_object *object)
{
	t_intersections	new_intersections;

	new_intersections.nb_of_intersections = 0;
	new_intersections.object = object;
	new_intersections.i1 = 0;
	new_intersections.i2 = 0;
	return (new_intersections);
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
	t_ray					ray2;

	ray2 = transform_ray_by_matrix(ray, ft_inverse_matrix(sphere->transform_m));
	w_origin = create_tuple(0, 0, 0, 1);
	sphere_to_ray = ft_sub_tuples(ray2.origin, w_origin);
	values.a = ft_tuple_scalarproduct(ray2.direction, ray2.direction);
	values.b = 2 * ft_tuple_scalarproduct(ray2.direction, sphere_to_ray);
	values.c = ft_tuple_scalarproduct(sphere_to_ray, sphere_to_ray) - 1;
	discriminant = powf(values.b, 2) - (4 * values.a * values.c);
	return (compute_sphere_intersections(sphere, discriminant, values));
}