/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margot <margot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:03:32 by mpourrey          #+#    #+#             */
/*   Updated: 2022/11/22 22:23:19 by margot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	*create_cone(t_data *data, t_tuple origin, double radius)
{
	t_object	*new_cone;
	t_list		*node;

	new_cone = malloc(sizeof(t_object));
	if (!new_cone)
		return (NULL);
	new_cone->id = ft_lstlen(data->world->objects);
	new_cone->object_type = CONE_TYPE;
	new_cone->transform_m = get_identity_matrix();
	new_cone->material = get_default_material();
	new_cone->min = 0;
	new_cone->max = 1;
	new_cone->is_capped = true;
	node = ft_lstnew(new_cone);
	if (!node)
	{
		free(new_cone);
		return (NULL);
	}
	ft_lstadd_back(&data->world->objects, node);
	return (new_cone);
}

static bool	check_cone_caps(t_ray ray, double i, double y)
{
	double	x;
	double	z;

	x = ray.origin.x + i * ray.direction.x;
	z = ray.origin.z + i * ray.direction.z;
	if (powf(x, 2) + powf(z, 2) <= y)
		return (true);
	return (false);
}

t_intersections	get_cone_caps_intersections(t_object *cone, t_ray ray, t_intersections intersections)
{
	double	tmp_i;

	/* check bottom cap */
	tmp_i = (cone->min - ray.origin.y) / ray.direction.y;
	if (check_cone_caps(ray, tmp_i, cone->min) == true)
	{
		if (intersections.nb_of_intersections == 0)
			intersections.i1 = tmp_i;
		else
			intersections.i2 = tmp_i;
		intersections.nb_of_intersections++;
	}
	/* check top cap */
	tmp_i = (cone->max - ray.origin.y) / ray.direction.y;
	if (check_cone_caps(ray, tmp_i, cone->max) == true)
	{
		if (intersections.nb_of_intersections == 0)
			intersections.i2 = tmp_i;
		else
			intersections.i2 = tmp_i;
		intersections.nb_of_intersections++;
	}
	return (intersections);
}


t_intersections	get_cone_intersections(t_object *cone, t_ray ray)
{
	t_double3		values;
	t_intersections	intersections;
	double			discriminant;
	double			y0;
	double			y1;
	double			tmp;

	intersections = init_intersections(cone);
	values.a = powf(ray.direction.x, 2) - powf(ray.direction.y, 2) + powf(ray.direction.z, 2);
	values.b = 2.0 * ray.origin.x * ray.direction.x - 2.0 * ray.origin.y * ray.direction.y + 2.0 * ray.origin.z * ray.direction.z;
	values.c = powf(ray.origin.x, 2) -  powf(ray.origin.y, 2) + powf(ray.origin.z, 2);
	// printf("a = %f\nb = %f\nc = %f\n", values.a, values.b, values.c);

	if (values.a >= -EPSILON && values.a <= EPSILON
		&& values.b >= -EPSILON && values.b <= EPSILON)
	{
		return(intersections);
	}
	else if (values.a >= -EPSILON && values.a <= EPSILON)
	{
		intersections.nb_of_intersections = 1;
		intersections.i1 = -values.c / (2 * values.b);
		return (intersections);
	}

	discriminant = powf(values.b, 2) - 4 * values.a * values.c;

	/* ray misses infinite cone */
	if (discriminant < 0)
	{
		return (intersections);
	}
	/* calcul des intersections */
	intersections.nb_of_intersections = 2;
	intersections.i1 = (-values.b - sqrtf(discriminant)) / (2.0 * values.a);
	intersections.i2 = (-values.b + sqrtf(discriminant)) / (2.0 * values.a);

	/* swap */
	if (intersections.i1 > intersections.i2)
	{
		tmp = intersections.i1;
		intersections.i1 = intersections.i2;
		intersections.i2 = tmp;
	}
	y0 = ray.origin.y + intersections.i1 * ray.direction.y;
	if (cone->min >= y0 || y0 >= cone->max)
	{
		intersections.nb_of_intersections--;
		intersections.i1 = intersections.i2;
	}
	y1 = ray.origin.y + intersections.i2 * ray.direction.y;
	if (cone->min >= y1 || y1 >= cone->max)
	{
		intersections.nb_of_intersections--;
		intersections.i2 = 0;
		if (intersections.nb_of_intersections == 0)
			intersections.i1 = 0;
	}
	if (intersections.object->is_capped == true && intersections.nb_of_intersections != 2)
	{
		intersections = get_cone_caps_intersections(intersections.object, ray, intersections);
	}
	return (intersections);
}

t_tuple	cone_normal_at(t_object *cone, t_tuple object_point)
{
	double	y;
	double	dist_from_y_axis;

	// dist_from_y_axis = powf(object_point.x, 2) + powf(object_point.z, 2);
	dist_from_y_axis = sqrt(powf(object_point.x, 2) + powf(object_point.z, 2));
	if (object_point.y > 0)
		dist_from_y_axis = -dist_from_y_axis;
	if (dist_from_y_axis < 1 && object_point.y >= cone->max - EPSILON)
		return (create_tuple(0, 1, 0, 0));
	else if (dist_from_y_axis < 1 && object_point.y <= cone->min + EPSILON)
		return (create_tuple(0, -1, 0, 0));
	else
		return (create_tuple(object_point.x, dist_from_y_axis, object_point.z, 0));
}
