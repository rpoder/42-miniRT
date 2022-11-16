/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:31:10 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/16 16:02:33 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	*create_cylinder(t_data *data, t_tuple origin, int radius)
{
	t_object	*new_cylinder;
	t_list		*node;

	new_cylinder = malloc(sizeof(t_object));
	if (!new_cylinder)
		return (NULL);
	// new_cylinder->id = ft_lstlen(data->world->objects);
	new_cylinder->object_type = CYLINDER_TYPE;
	new_cylinder->transform_m = get_identity_matrix();
	new_cylinder->material = get_default_material();
	new_cylinder->min = -11;
	new_cylinder->max = 2;
	// node = ft_lstnew(new_cylinder);
	// if (!node)
	// {
	// 	free(new_cylinder);
	// 	return (NULL);
	// }
	// ft_lstadd_back(&data->world->objects, node);
	return (new_cylinder);
}

t_tuple	cylinder_normal_at(t_object *cylinder, t_tuple object_point)
{
	return (create_tuple(object_point.x, 0, object_point.z, 0));
}

t_intersections	get_cylinder_intersections(t_object *cylinder, t_ray ray)
{
	t_double3		values;
	t_intersections	intersections;
	t_intersections	tmp_intersections;
	double			discriminant;
	double			y0;
	double			y1;
	double			tmp;

	tmp_intersections = init_intersections(cylinder);
	values.a = powf(ray.direction.x, 2) + powf(ray.direction.z, 2);

	/* ray is parallel to y axis */
	if (values.a <= EPSILON)
		return (tmp_intersections);
	values.b = 2.0 * ray.origin.x * ray.direction.x + 2.0 * ray.origin.z * ray.direction.z;
	values.c = powf(ray.origin.x, 2) +  powf(ray.origin.z, 2) - 1.0;
	discriminant = powf(values.b, 2) - 4 * values.a * values.c;

	/* ray misses */
	if (discriminant < 0)
		return (tmp_intersections);
	tmp_intersections.nb_of_intersections = 2;
	tmp_intersections.i1 = (-values.b - sqrtf(discriminant)) / (2.0 * values.a);
	tmp_intersections.i2 = (-values.b + sqrtf(discriminant)) / (2.0 * values.a);

	if (tmp_intersections.i1 > tmp_intersections.i2)
	{
		tmp = tmp_intersections.i1;
		tmp_intersections.i1 = tmp_intersections.i2;
		tmp_intersections.i2 = tmp;
	}

	intersections = init_intersections(cylinder);
	y0 = ray.origin.y + tmp_intersections.i1 * ray.direction.y;
	if (cylinder->min < y0 && y0 < cylinder->max)
	{
		intersections.nb_of_intersections++;
		intersections.i1 = tmp_intersections.i1;
	}
	if (cylinder->min < y1 && y1 < cylinder->max)
	{
		intersections.nb_of_intersections++;
		if (intersections.nb_of_intersections == 0)
			intersections.i1 = tmp_intersections.i2;
		else
			intersections.i2 = tmp_intersections.i2;
	}
	return (intersections);
}
