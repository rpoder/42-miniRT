/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_normal_and_intersections.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 23:24:49 by rpoder            #+#    #+#             */
/*   Updated: 2022/12/01 00:13:28 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	get_triangle_normal_at(t_object *triangle)
{
	return (triangle->triangle_cars.normal);
}

static	t_triangle_intersections_tool	does_not_intersect_triangle(
	t_object *triangle, t_ray ray)
{
	t_triangle_intersections_tool	t;

	t.does_intersect = true;
	t.dir_cross_e2 = cross_product(ray.direction, triangle->triangle_cars.e2);
	t.determinant = dot_product(triangle->triangle_cars.e1, t.dir_cross_e2);
	if (fabs(t.determinant) < EPSILON)
	{
		t.does_intersect = false;
		return (t);
	}
	t.f = 1.0 / t.determinant;
	t.p1_to_origin = sub_tuples(ray.origin, triangle->triangle_cars.p1);
	t.u = t.f * dot_product(t.p1_to_origin, t.dir_cross_e2);
	if (t.u < 0.0 || t.u > 1)
	{
		t.does_intersect = false;
		return (t);
	}
	t.origin_cross_e1 = cross_product(t.p1_to_origin,
			triangle->triangle_cars.e1);
	t.v = t.f * dot_product(ray.direction, t.origin_cross_e1);
	if (t.v < 0 || (t.u + t.v) > 1)
		t.does_intersect = false;
	return (t);
}

t_intersections	get_triangle_intersections(t_object *triangle, t_ray ray)
{
	t_intersections					intersections;
	t_triangle_intersections_tool	tool;
	double							t;

	intersections = init_intersections(triangle);
	tool = does_not_intersect_triangle(triangle, ray);
	if (tool.does_intersect == false)
	{
		intersections.nb_of_intersections = 0;
		return (intersections);
	}
	t = tool.f * dot_product(triangle->triangle_cars.e2, tool.origin_cross_e1);
	intersections.nb_of_intersections = 1;
	intersections.i1 = t;
	intersections.i2 = t;
	return (intersections);
}
