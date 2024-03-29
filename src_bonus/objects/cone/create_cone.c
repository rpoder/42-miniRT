/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:40:37 by mpourrey          #+#    #+#             */
/*   Updated: 2022/12/02 19:14:15 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	*create_cone(t_data *data, t_cone_values_tool values)
{
	t_object	*new_cone;
	t_list		*node;

	new_cone = malloc(sizeof(t_object));
	if (!new_cone)
		return (NULL);
	new_cone->id = ft_lstlen(data->world->objects);
	new_cone->object_type = CONE_TYPE;
	new_cone->material = get_default_material();
	new_cone->material.color = values.color;
	new_cone->min = 0 ;
	new_cone->max = 1;
	new_cone->is_capped = true;
	new_cone->transform_m = translate_and_scale_object(values.origin,
			values.radius);
	new_cone->transform_m = orient_object(new_cone, values.orientation_vector);
	new_cone->transform_m = multiply_matrices(new_cone->transform_m,
			compute_rotation_z_matrix(M_PI));
	node = ft_lstnew(new_cone);
	if (!node)
		return (free(new_cone), NULL);
	ft_lstadd_back(&data->world->objects, node);
	return (new_cone);
}
