/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_intersections_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:58:33 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/30 21:59:23 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static bool	check_cone_caps(t_ray ray, double i, double y)
{
	double	x;
	double	z;

	x = ray.origin.x + i * ray.direction.x;
	z = ray.origin.z + i * ray.direction.z;
	if (powf(x, 2) + powf(z, 2) <= y)
		return (true);
	return (false);
}

t_intersections	get_cone_caps_intersections(t_object *cone,
	t_ray ray, t_intersections intersections)
{
	double	tmp_i;

	tmp_i = (cone->min - ray.origin.y) / ray.direction.y;
	if (check_cone_caps(ray, tmp_i, cone->min) == true)
	{
		if (intersections.nb_of_intersections == 0)
			intersections.i1 = tmp_i;
		else
			intersections.i2 = tmp_i;
		intersections.nb_of_intersections++;
	}
	tmp_i = (cone->max - ray.origin.y) / ray.direction.y;
	if (check_cone_caps(ray, tmp_i, cone->max) == true)
	{
		if (intersections.nb_of_intersections == 0)
			intersections.i2 = tmp_i;
		else
			intersections.i2 = tmp_i;
		intersections.nb_of_intersections++;
	}
	return (intersections);
}
