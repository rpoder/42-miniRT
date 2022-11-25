/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cube.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:42:28 by mpourrey          #+#    #+#             */
/*   Updated: 2022/11/25 19:42:47 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	*create_cube(t_data *data)
{
	t_object	*new_cube;
	t_list		*node;

	new_cube = malloc(sizeof(t_object));
	if (!new_cube)
		return (NULL);
	new_cube->id = ft_lstlen(data->world->objects);
	new_cube->object_type = CUBE_TYPE;
	new_cube->material = get_default_material();
	new_cube->transform_m = get_identity_matrix();
	node = ft_lstnew(new_cube);
	if (!node)
	{
		free(new_cube);
		return (NULL);
	}
	ft_lstadd_back(&data->world->objects, node);
	return (new_cube);
}