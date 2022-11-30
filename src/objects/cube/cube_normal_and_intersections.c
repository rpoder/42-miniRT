/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_normal_and_intersections.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 01:09:41 by mpourrey          #+#    #+#             */
/*   Updated: 2022/11/30 01:15:16 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_cube_faces_intersections	check_axis(double origin, double direction)
{
	t_cube_faces_intersections	faces_intersections;
	double						t_min_numerator;
	double						t_max_numerator;
	double						tmp;

	t_min_numerator = (-1.0 - origin);
	t_max_numerator = (1.0 - origin);
	if (fabs(direction) >= EPSILON)
	{
		faces_intersections.t_min = t_min_numerator / direction;
		faces_intersections.t_max = t_max_numerator / direction;
	}
	else
	{
		faces_intersections.t_min = t_min_numerator * INFINITY;
		faces_intersections.t_max = t_max_numerator * INFINITY;
	}
	if (faces_intersections.t_min > faces_intersections.t_max)
	{
		tmp = faces_intersections.t_min;
		faces_intersections.t_min = faces_intersections.t_max;
		faces_intersections.t_max = tmp;
	}

	return (faces_intersections);
}

static	double get_min(double a, double b, double c)
{
	if (a <= b && a <= c)
		return (a);
	else if (b <= a && b <= c)
		return (b);
	else
		return (c);
}

static	double get_max(double a, double b, double c)
{
	if (a >= b && a >= c)
		return (a);
	else if (b >= a && b >= c)
		return (b);
	else
		return (c);
}

t_intersections	get_cube_intersections(t_object *cube, t_ray ray)
{
	t_intersections				cube_intersections;
	t_cube_faces_intersections	faces_intersections_x;
	t_cube_faces_intersections	faces_intersections_y;
	t_cube_faces_intersections	faces_intersections_z;

	cube_intersections = init_intersections(cube);
	faces_intersections_x = check_axis(ray.origin.x, ray.direction.x);
	faces_intersections_y = check_axis(ray.origin.y, ray.direction.y);
	faces_intersections_z = check_axis(ray.origin.z, ray.direction.z);
	cube_intersections.i1 = get_max(faces_intersections_x.t_min, faces_intersections_y.t_min, faces_intersections_z.t_min);
	cube_intersections.i2 = get_min(faces_intersections_x.t_max, faces_intersections_y.t_max, faces_intersections_z.t_max);
	if (cube_intersections.i1 < cube_intersections.i2)
		cube_intersections.nb_of_intersections = 2;
	else
		cube_intersections.nb_of_intersections = 0;
	return (cube_intersections);
}

t_tuple	get_cube_normal_at(t_object *cube, t_tuple point)
{
	double	maxc;

	maxc = get_max(fabs(point.x), fabs(point.y), fabs(point.z));
	if (maxc == fabs(point.x))
		return (create_tuple(point.x, 0, 0, 1));
	else if (maxc == fabs(point.y))
		return (create_tuple(0, point.y, 0, 1));
	else
		return (create_tuple(0, 0, point.z, 1));
}