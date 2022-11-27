/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_normal_and_intersections.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 23:24:49 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/28 00:33:59 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	get_triangle_normal_at(t_object *triangle, t_tuple object_point)
{
	return (triangle->triangle_cars.normal);
}

t_intersections	get_triangle_intersections(t_object *triangle, t_ray ray)
{
	t_intersections	intersections;
	double			determinant;
	double			f;
	double			u;
	double			v;
	double			t;
	t_tuple			dir_cross_e2;
	t_tuple			p1_to_origin;
	t_tuple			origin_cross_e1;


	intersections = init_intersections(triangle);
	dir_cross_e2 = cross_product(ray.direction, triangle->triangle_cars.e2);
	determinant = dot_product(triangle->triangle_cars.e1, dir_cross_e2);
	if (fabs(determinant) < EPSILON)
	{
		intersections.nb_of_intersections = 0;
		return (intersections);
	}
	f = 1.0 / determinant;
	p1_to_origin = sub_tuples(ray.origin, triangle->triangle_cars.p1);
	u = f * dot_product(p1_to_origin, dir_cross_e2);
	if (u < 0.0 || u > 1)
	{
		intersections.nb_of_intersections = 0;
		return (intersections);
	}
	origin_cross_e1 = cross_product(p1_to_origin, triangle->triangle_cars.e1);
	v = f * dot_product(ray.direction, origin_cross_e1);
	if (v < 0 || (u + v) > 1)
	{
		intersections.nb_of_intersections = 0;
		return (intersections);
	}
	t = f * dot_product(triangle->triangle_cars.e2, origin_cross_e1);
	intersections.nb_of_intersections = 1;
	intersections.i1 = t;
	intersections.i2 = t;
	return (intersections);
}
