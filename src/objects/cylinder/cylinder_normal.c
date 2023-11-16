/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_normal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:31:10 by rpoder            #+#    #+#             */
/*   Updated: 2022/12/01 00:12:41 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	get_cylinder_normal_at(t_object *cylinder, t_tuple object_point)
{
	double	dist_from_y_axis;

	dist_from_y_axis = powf(object_point.x, 2) + powf(object_point.z, 2);
	if (dist_from_y_axis < 1 && object_point.y >= cylinder->max - EPSILON)
		return (create_tuple(0, 1, 0, 0));
	else if (dist_from_y_axis < 1 && object_point.y <= cylinder->min + EPSILON)
		return (create_tuple(0, -1, 0, 0));
	else
		return (create_tuple(object_point.x, 0, object_point.z, 0));
}
