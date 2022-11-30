/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_normal_and_intersections.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 23:24:49 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/30 20:12:25 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	get_triangle_normal_at(t_object *triangle, t_tuple object_point)
{
	return (triangle->triangle_cars.normal);
}

static	t_triangle_intersections_tool	does_not_intersect_triangle(
	t_object *triangle, t_ray ray)
{
	t_triangle_intersections_tool	tool;

	tool.does_intersect = true;
	tool.dir_cross_e2 = cross_product(ray.direction, triangle->triangle_cars.e2);

	tool.determinant = dot_product(triangle->triangle_cars.e1, tool.dir_cross_e2);
	if (fabs(tool.determinant) < EPSILON)
	{
		tool.does_intersect = false;
		return (tool);
	}

	tool.f = 1.0 / tool.determinant;
	tool.p1_to_origin = sub_tuples(ray.origin, triangle->triangle_cars.p1);
	tool.u = tool.f * dot_product(tool.p1_to_origin, tool.dir_cross_e2);
	
	if (tool.u < 0.0 || tool.u > 1)
	{
		tool.does_intersect = false;
		return (tool);
	}
	tool.origin_cross_e1 = cross_product(tool.p1_to_origin, triangle->triangle_cars.e1);
	tool.v = tool.f * dot_product(ray.direction, tool.origin_cross_e1);
	if (tool.v < 0 || (tool.u + tool.v) > 1)
	{
		tool.does_intersect = false;
		return (tool);
	}
	return (tool);
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
