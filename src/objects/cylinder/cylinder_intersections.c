/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_intersections.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:25:05 by mpourrey          #+#    #+#             */
/*   Updated: 2022/11/30 14:47:50 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	check_cylinder_caps(t_ray ray, double i)
{
	double	x;
	double	z;

	x = ray.origin.x + i * ray.direction.x;
	z = ray.origin.z + i * ray.direction.z;
	if (powf(x, 2) + powf(z, 2) <= 1)
		return (true);
	return (false);
}

t_intersections	get_cylinder_caps_intersections(t_object *cylinder, t_ray ray,
		t_intersections intersections)
{
	double	tmp_i;

	tmp_i = (cylinder->min - ray.origin.y) / ray.direction.y;
	if (check_cylinder_caps(ray, tmp_i) == true)
	{
		if (intersections.nb_of_intersections == 0)
			intersections.i1 = tmp_i;
		else
			intersections.i2 = tmp_i;
		intersections.nb_of_intersections++;
	}
	tmp_i = (cylinder->max - ray.origin.y) / ray.direction.y;
	if (check_cylinder_caps(ray, tmp_i) == true)
	{
		if (intersections.nb_of_intersections == 0)
			intersections.i2 = tmp_i;
		else
			intersections.i2 = tmp_i;
		intersections.nb_of_intersections++;
	}
	return (intersections);
}

static t_intersections	compute_cyl_intersections(t_object *cylinder, t_ray ray,
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
	if (cylinder->min >= y0 || y0 >= cylinder->max)
	{
		intersections.nb_of_intersections--;
		intersections.i1 = intersections.i2;
	}
	y1 = ray.origin.y + intersections.i2 * ray.direction.y;
	if (cylinder->min >= y1 || y1 >= cylinder->max)
	{
		intersections.nb_of_intersections--;
		intersections.i2 = 0;
		if (intersections.nb_of_intersections == 0)
			intersections.i1 = 0;
	}
	return (intersections);
}

t_intersections	get_cylinder_intersections(t_object *cylinder, t_ray ray)
{
	t_double3		values;
	t_intersections	inters;
	double			discriminant;

	inters = init_intersections(cylinder);
	values.a = powf(ray.direction.x, 2) + powf(ray.direction.z, 2);
	if (values.a <= EPSILON)
		return (get_cylinder_caps_intersections(inters.object, ray, inters));
	values.b = 2.0 * ray.origin.x * ray.direction.x + 2.0 * ray.origin.z
		* ray.direction.z;
	values.c = powf(ray.origin.x, 2) + powf(ray.origin.z, 2) - 1.0;
	discriminant = powf(values.b, 2) - 4 * values.a * values.c;
	if (discriminant < 0)
		return (get_cylinder_caps_intersections(inters.object, ray, inters));
	inters.nb_of_intersections = 2;
	inters.i1 = (-values.b - sqrtf(discriminant)) / (2.0 * values.a);
	inters.i2 = (-values.b + sqrtf(discriminant)) / (2.0 * values.a);
	inters = compute_cyl_intersections(cylinder, ray, inters);
	if (inters.object->is_capped == true && inters.nb_of_intersections != 2)
		inters = get_cylinder_caps_intersections(inters.object, ray, inters);
	return (inters);
}
