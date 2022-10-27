/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:01:36 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/26 18:22:37 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	*ft_create_sphere(t_data *data, t_tuple origin, int radius)
{
	t_object	*new_sphere;
	t_list		*node;

	new_sphere = malloc(sizeof(t_object));
	if (!new_sphere)
		return (NULL);
	// new_sphere->id = ft_lstlen(data->objects);
	new_sphere->origin = origin;
	new_sphere->radius = radius;
	new_sphere->transform_m = ft_get_identity_matrix();
	// node = ft_lstnew(new_sphere);
	// if (!node)
	// {
	// 	free(new_sphere);
	// 	return (NULL);
	// }
	// ft_lstadd_back(&data->objects, node);
	return (new_sphere);
}

t_tuple	sphere_normal_at(t_object sphere, t_tuple world_point)
{
	t_tuple	origin;
	t_tuple	object_point;
	t_tuple	world_normal;
	t_tuple	object_normal;

	object_point = ft_multiply_tuple_by_matrix(world_point,
		ft_inverse_matrix(sphere.transform_m));
	origin = ft_create_tuple(0, 0, 0, 1);
	object_normal = ft_sub_tuples(object_point, origin);
// 	if (ft_tuple_len(object_normal) != 1)
//		ft_putstr_fd("ERR - This point is not on the sphere.\n", 2);
	world_normal = ft_multiply_tuple_by_matrix(object_normal,
		ft_inverse_matrix(sphere.transform_m));
	world_normal.w = 0;
	world_normal = ft_normalize_tuple(world_normal);
	return (world_normal);
}
