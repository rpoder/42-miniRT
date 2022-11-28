/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_triangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 22:29:47 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/28 00:12:15 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	*create_triangle(t_data *data, t_triangle_values_tool values)
{
	t_object	*new_triangle;
	t_list		*node;

	new_triangle = malloc(sizeof(t_object));
	if (!new_triangle)
		return (NULL);
	new_triangle->id = ft_lstlen(data->world->objects);
	new_triangle->object_type = TRIANGLE_TYPE;
	new_triangle->transform_m = get_identity_matrix();
	new_triangle->material = get_default_material();
	new_triangle->material.color = values.color;
	new_triangle->triangle_cars.p1 = values.p1;
	new_triangle->triangle_cars.p2 = values.p2;
	new_triangle->triangle_cars.p3 = values.p3;
	new_triangle->triangle_cars.e1 = sub_tuples(new_triangle->triangle_cars.p2, new_triangle->triangle_cars.p1);
	new_triangle->triangle_cars.e2 = sub_tuples(new_triangle->triangle_cars.p3, new_triangle->triangle_cars.p1);
	new_triangle->triangle_cars.normal = normalize_tuple(cross_product(new_triangle->triangle_cars.e2,
		new_triangle->triangle_cars.e1));
	node = ft_lstnew(new_triangle);
	if (!node)
	{
		free(new_triangle);
		return (NULL);
	}
	ft_lstadd_back(&data->world->objects, node);
	return (new_triangle);
}