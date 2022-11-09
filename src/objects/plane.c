/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ronanpoder <ronanpoder@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:43:54 by ronanpoder        #+#    #+#             */
/*   Updated: 2022/11/09 16:15:32 by ronanpoder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	*create_plane(t_data *data)
{
	t_object	*new_plane;
	t_list		*node;

	new_plane = malloc(sizeof(t_object));
	if (!new_plane)
		return (NULL);
	new_plane->id = ft_lstlen(data->world->objects);
	new_plane->object_type = PLANE_TYPE;
	new_plane->transform_m = get_identity_matrix();
	new_plane->material = get_default_material();
	node = ft_lstnew(new_plane);
	if (!node)
	{
		free(new_plane);
		return (NULL);
	}
	ft_lstadd_back(&data->world->objects, node);
	return (new_plane);
}

t_intersections	get_plane_intersections(t_object *plane, t_ray ray)
{
	t_intersections	intersections;

	intersections = init_intersections(plane);
	if (fabs(ray.direction.y) < EPSILON)
		intersections.nb_of_intersections = 0;
	else
	{
		intersections.nb_of_intersections = 1;
		intersections.i1 = -ray.origin.y / ray.direction.y;
	}
	return (intersections);
}

t_tuple	plane_normal_at(void)
{
	return (create_tuple(0, 1, 0, 0));
}
