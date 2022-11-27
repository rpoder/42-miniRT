/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_normal_and_intersections.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:43:54 by ronanpoder        #+#    #+#             */
/*   Updated: 2022/11/27 18:53:32 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_intersections	get_plane_intersections(t_object *plane, t_ray ray)
{
	t_intersections	intersections;

	intersections = init_intersections(plane);
	if (fabs(ray.direction.y) < EPSILON)
	{
		intersections.nb_of_intersections = 0;
	}
	else
	{
		intersections.nb_of_intersections = 1;
		// printray(ray);
		intersections.i1 = -ray.origin.y / ray.direction.y;
		// print_intersection(intersections);
	}
	return (intersections);
}

t_tuple	get_plane_normal_at(void)
{
	return (create_tuple(0, 1, 0, 0));
}
