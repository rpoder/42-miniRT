/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:31:10 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/19 18:19:43 by mpourrey         ###   ########.fr       */
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
	new_cylinder->id = ft_lstlen(data->world->objects);
	new_cylinder->object_type = CYLINDER_TYPE;
	new_cylinder->transform_m = get_identity_matrix();
	new_cylinder->material = get_default_material();
	new_cylinder->min = 1;
	new_cylinder->max = 2;
	new_cylinder->is_capped = true;
	node = ft_lstnew(new_cylinder);
	if (!node)
	{
		free(new_cylinder);
		return (NULL);
	}
	ft_lstadd_back(&data->world->objects, node);
	return (new_cylinder);
}

t_tuple	cylinder_normal_at(t_object *cylinder, t_tuple object_point)
{
	double	dist_from_y_axis;

	dist_from_y_axis = powf(object_point.x, 2) + powf(object_point.z, 2);
	if (dist_from_y_axis < 1 && object_point.y >= cylinder->max - EPSILON)
		return (create_tuple(0, 1, 0, 0));
	else if (dist_from_y_axis < 1 && object_point.y <= cylinder->min + EPSILON)
		return (create_tuple(0, -1, 0, 0));
	else
		return (create_tuple(object_point.x, 0, object_point.z, 0));
}

static bool	check_caps(t_ray ray, double i)
{
	double	x;
	double	z;

	x = ray.origin.x + i * ray.direction.x;
	z = ray.origin.z + i * ray.direction.z;
	if (powf(x, 2) + powf(z, 2) <= 1)
		return (true);
	return (false);
}

t_intersections	get_caps_intersections(t_object *cylinder, t_ray ray, t_intersections intersections)
{
	double	tmp_i;

	/* check bottom cap */
	tmp_i = (cylinder->min - ray.origin.y) / ray.direction.y;
	if (check_caps(ray, tmp_i) == true)
	{	
		if (intersections.nb_of_intersections == 0)
			intersections.i1 = tmp_i;
		else
			intersections.i2 = tmp_i;
		intersections.nb_of_intersections++;
	}
	/* check top cap */
	tmp_i = (cylinder->max - ray.origin.y) / ray.direction.y;
	if (check_caps(ray, tmp_i) == true)
	{
		if (intersections.nb_of_intersections == 0)
			intersections.i2 = tmp_i;
		else
			intersections.i2 = tmp_i;
		intersections.nb_of_intersections++;
	}
	return (intersections);
}

t_intersections	get_cylinder_intersections(t_object *cylinder, t_ray ray)
{
	t_double3		values;
	t_intersections	intersections;
	double			discriminant;
	double			y0;
	double			y1;
	double			tmp;

	intersections = init_intersections(cylinder);
	values.a = powf(ray.direction.x, 2) + powf(ray.direction.z, 2);

	/* ray is parallel to y axis */
	if (values.a <= EPSILON)
		return (get_caps_intersections(intersections.object, ray, intersections));
		
	values.b = 2.0 * ray.origin.x * ray.direction.x + 2.0 * ray.origin.z * ray.direction.z;
	values.c = powf(ray.origin.x, 2) +  powf(ray.origin.z, 2) - 1.0;
	discriminant = powf(values.b, 2) - 4 * values.a * values.c;

	/* ray misses infinite cylinder */
	if (discriminant < 0)
		return (get_caps_intersections(intersections.object, ray, intersections));
	
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
	if (cylinder->min >= y0 || y0 >= cylinder->max)
	{
		intersections.nb_of_intersections--;
		intersections.i1 = intersections.i2;
	}
	y1 = ray.origin.y + intersections.i2 * ray.direction.y;
	if (cylinder->min >= y1 || y1 >= cylinder->max)
	{
		intersections.nb_of_intersections--;
		intersections.i2 = 0;
		if (intersections.nb_of_intersections == 0)
			intersections.i1 = 0;
	}
	print_intersection(intersections);

	if (intersections.object->is_capped == true && intersections.nb_of_intersections != 2)
		intersections = get_caps_intersections(intersections.object, ray, intersections);
	print_intersection(intersections);
	return (intersections);
}
