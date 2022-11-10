/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_intersections.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:48:27 by margot            #+#    #+#             */
/*   Updated: 2022/11/10 15:35:49 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_intersections	init_intersections(t_object *object)
{
	t_intersections	new_intersections;

	new_intersections.nb_of_intersections = 0;
	new_intersections.object = object;
	new_intersections.i1 = 0;
	new_intersections.i2 = 0;
	return (new_intersections);
}

t_intersections	get_object_intersections(t_object *object, t_ray ray)
{
	t_intersections	ret;
	t_ray			ray2;

	ray2 = 	transform_ray_by_matrix(ray, ft_inverse_matrix(object->transform_m));
	if (object->object_type == SPHERE_TYPE)
		ret = get_sphere_intersections(object, ray2);
	else if (object->object_type == PLANE_TYPE)
		ret = get_plane_intersections(object, ray2);
	else if (object->object_type == CUBE_TYPE)
		ret = get_cube_intersections(object, ray2);
	else
	{
		printf("ERR: No object_type.");
		exit(1);
	}
	return (ret);
}
