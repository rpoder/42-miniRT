/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_normal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:38:38 by mpourrey          #+#    #+#             */
/*   Updated: 2022/11/26 22:10:44 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	get_cone_normal_at(t_object *cone, t_tuple object_point)
{
	double	y;
	double	dist_from_y_axis;

	// dist_from_y_axis = powf(object_point.x, 2) + powf(object_point.z, 2);
	dist_from_y_axis = sqrt(powf(object_point.x, 2) + powf(object_point.z, 2));
	if (object_point.y > 0)
		dist_from_y_axis = -dist_from_y_axis;
	if (dist_from_y_axis < 1 && object_point.y >= cone->max - EPSILON)
		return (create_tuple(0, 1, 0, 0));
	else if (dist_from_y_axis < 1 && object_point.y <= cone->min + EPSILON)
		return (create_tuple(0, -1, 0, 0));
	else
		return (create_tuple(object_point.x, dist_from_y_axis, object_point.z, 0));
}