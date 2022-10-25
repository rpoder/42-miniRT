/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:01:36 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/24 17:58:44 by rpoder           ###   ########.fr       */
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
