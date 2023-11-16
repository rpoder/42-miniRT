/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_intersections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:03:32 by mpourrey          #+#    #+#             */
/*   Updated: 2022/12/01 00:07:52 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_intersections	compute_cone_intersections(t_object *cone, t_ray ray,
		t_intersections intersections)
{
	double	y0;
	double	y1;
	double	tmp;

	if (intersections.i1 > intersections.i2)
	{
		tmp = intersections.i1;
		intersections.i1 = intersections.i2;
		intersections.i2 = tmp;
	}
	y0 = ray.origin.y + intersections.i1 * ray.direction.y;
	if (cone->min >= y0 || y0 >= cone->max)
	{
		intersections.nb_of_intersections--;
		intersections.i1 = intersections.i2;
	}
	y1 = ray.origin.y + intersections.i2 * ray.direction.y;
	if (cone->min >= y1 || y1 >= cone->max)
	{
		intersections.nb_of_intersections--;
		intersections.i2 = 0;
		if (intersections.nb_of_intersections == 0)
			intersections.i1 = 0;
	}
	return (intersections);
}

static t_double3	compute_cone_values(t_ray ray)
{
	t_double3	values;

	values.a = powf(ray.direction.x, 2) - powf(ray.direction.y, 2)
		+ powf(ray.direction.z, 2);
	values.b = 2.0 * ray.origin.x * ray.direction.x
		- 2.0 * ray.origin.y * ray.direction.y + 2.0 * ray.origin.z
		* ray.direction.z;
	values.c = powf(ray.origin.x, 2) - powf(ray.origin.y, 2)
		+ powf(ray.origin.z, 2);
	return (values);
}

t_intersections	does_not_or_one_inters(t_object *cone, t_double3 values)
{
	t_intersections	intersections;

	intersections = init_intersections(cone);
	if (values.a >= -EPSILON && values.a <= EPSILON
		&& values.b >= -EPSILON && values.b <= EPSILON)
	{
		return (intersections);
	}
	else if (values.a >= -EPSILON && values.a <= EPSILON)
	{
		intersections.nb_of_intersections = 1;
		intersections.i1 = -values.c / (2 * values.b);
		return (intersections);
	}
	return (intersections);
}

t_intersections	get_cone_intersections(t_object *cone, t_ray ray)
{
	t_double3		values;
	t_intersections	intersections;
	double			discriminant;

	values = compute_cone_values(ray);
	intersections = does_not_or_one_inters(cone, values);
	discriminant = powf(values.b, 2) - 4 * values.a * values.c;
	if (discriminant < 0)
		return (intersections);
	intersections.nb_of_intersections = 2;
	intersections.i1 = (-values.b - sqrtf(discriminant)) / (2.0 * values.a);
	intersections.i2 = (-values.b + sqrtf(discriminant)) / (2.0 * values.a);
	intersections = compute_cone_intersections(cone, ray, intersections);
	if (intersections.object->is_capped == true
		&& intersections.nb_of_intersections != 2)
		intersections = get_cone_caps_intersections(intersections.object,
				ray, intersections);
	return (intersections);
}
