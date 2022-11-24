/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margot <margot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:43:54 by ronanpoder        #+#    #+#             */
/*   Updated: 2022/11/23 19:38:09 by margot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	transform_plane_orientation(t_object *plane, t_tuple orientation)
{
	float	radian_x;
	float	radian_y;
	float	radian_z;
	
	//si -1 >> -90 degres >> M_PI  
	//si 1 >> 90 degres >> - M_PI
	
	if (orientation.x > 0.0 + EPSILON || orientation.x < 0.0 - EPSILON)
	{
		radian_x = (orientation.x * 90) * M_PI / 180;
		plane->transform_m = ft_multiply_matrices(plane->transform_m, compute_rotation_x_matrix(radian_x));
	}
	if (orientation.y > 0.0 + EPSILON || orientation.y < 0.0 - EPSILON)
	{
		radian_y = (orientation.x * 90) * M_PI / 180;
		plane->transform_m = ft_multiply_matrices(plane->transform_m, compute_rotation_y_matrix(radian_y));
	}
		if (orientation.z > 0.0 + EPSILON || orientation.z < 0.0- EPSILON)
	{
		radian_z = (orientation.z * 90) * M_PI / 180;
		plane->transform_m = ft_multiply_matrices(plane->transform_m, compute_rotation_z_matrix(radian_z));
	}
}

static t_matrix4 compute_parsing_plane_transform_m(t_tuple origin)
{
	t_matrix4	transform_m;
	
	transform_m = get_identity_matrix();
	if (origin.x != 0.0 || origin.y != 0.0 || origin.x != 0.0)
		transform_m = compute_translation_matrix(origin.x, origin.y, origin.z);
	return (transform_m);
}

t_object	*create_plane(t_data *data, t_tuple	origin)
{
	t_object	*new_plane;
	t_list		*node;

	new_plane = malloc(sizeof(t_object));
	if (!new_plane)
		return (NULL);
	new_plane->id = ft_lstlen(data->world->objects);
	new_plane->object_type = PLANE_TYPE;
	new_plane->transform_m = compute_parsing_plane_transform_m(origin);
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
