/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:03:32 by mpourrey          #+#    #+#             */
/*   Updated: 2022/11/19 18:31:37 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	*create_cone(t_data *data, t_tuple origin, int radius)
{
	t_object	*new_cylinder;
	t_list		*node;

	new_cylinder = malloc(sizeof(t_object));
	if (!new_cylinder)
		return (NULL);
	new_cylinder->id = ft_lstlen(data->world->objects);
	new_cylinder->object_type = CONE_TYPE;
	new_cylinder->transform_m = get_identity_matrix();
	new_cylinder->material = get_default_material();
	new_cylinder->min = 1;
	new_cylinder->max = 2;
	new_cylinder->is_capped = false;
	node = ft_lstnew(new_cylinder);
	if (!node)
	{
		free(new_cylinder);
		return (NULL);
	}
	ft_lstadd_back(&data->world->objects, node);
	return (new_cylinder);
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
	/* ray is parallel to y axis */
	if (values.a <= EPSILON && values.b <= EPSILON)
	{
		printf("un truc\n");
	}
	else if (values.a <= EPSILON && values.b > EPSILON)
	{
		intersections.nb_of_intersections = 1;
		intersections.i1 = -values.c / (2 * values.b);
	}

	discriminant = powf(values.b, 2) - 4 * values.a * values.c;

	/* ray misses infinite cone */
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
	// y0 = ray.origin.y + intersections.i1 * ray.direction.y;
	// if (cone->min >= y0 || y0 >= cone->max)
	// {
	// 	intersections.nb_of_intersections--;
	// 	intersections.i1 = intersections.i2;
	// }
	// y1 = ray.origin.y + intersections.i2 * ray.direction.y;
	// if (cone->min >= y1 || y1 >= cone->max)
	// {
	// 	intersections.nb_of_intersections--;
	// 	intersections.i2 = 0;
	// 	if (intersections.nb_of_intersections == 0)
	// 		intersections.i1 = 0;
	// }
	if (intersections.object->is_capped == true && intersections.nb_of_intersections != 2)
	{
		intersections = get_caps_intersections(intersections.object, ray, intersections);
	}
	return (intersections);
}