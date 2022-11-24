/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margot <margot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:01:36 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/23 18:07:43 by margot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_matrix4	compute_parsing_sphere_transform_m(t_tuple origin, double radius)
{
	t_matrix4	t1;
	t_matrix4	t2;
	t_matrix4	transform_matrix;

	t1 = get_identity_matrix();
	if (origin.x != 0.0 || origin.y != 0.0 || origin.x != 0.0)
		t1 = compute_translation_matrix(origin.x, origin.y, origin.z);
	t2 = compute_scaling_matrix(radius, radius, radius);
	transform_matrix = ft_multiply_matrices(t1, t2);
	return (transform_matrix);
}

t_object	*create_sphere(t_data *data, t_tuple origin, double radius)
{
	t_object	*new_sphere;
	t_list		*node;

	new_sphere = malloc(sizeof(t_object));
	if (!new_sphere)
		return (NULL);
	new_sphere->id = ft_lstlen(data->world->objects);
	new_sphere->object_type = SPHERE_TYPE;
	new_sphere->transform_m = compute_parsing_sphere_transform_m(origin, radius);
	new_sphere->material = get_default_material();
	node = ft_lstnew(new_sphere);
	if (!node)
	{
		free(new_sphere);
		return (NULL);
	}
	ft_lstadd_back(&data->world->objects, node);
	return (new_sphere);
}

t_tuple	sphere_normal_at(t_object *sphere, t_tuple object_point)
{
	t_tuple	origin;
	t_tuple	object_normal;

	origin = create_tuple(0, 0, 0, 1);
	object_normal = ft_sub_tuples(object_point, origin);
	return (object_normal);
}

static t_intersections	compute_sphere_intersections(t_object *object, double discr, t_double3 values)
{
	t_intersections	intersections;

	intersections = init_intersections(object);
	if (discr < 0)
	{
		intersections.nb_of_intersections = 0;
	}
	if (discr == 0)
	{
		intersections.nb_of_intersections = 1;
		intersections.i1 = (- values.b - sqrtf(discr)) / (2 * values.a);
		intersections.i2 = (- values.b + sqrtf(discr)) / (2 * values.a);
	}
	else if (discr > 0)
	{
		intersections.nb_of_intersections = 2;
		intersections.i1 = (- values.b - sqrtf(discr)) / (2 * values.a);
		intersections.i2 = (- values.b + sqrtf(discr)) / (2 * values.a);
	}
	return (intersections);
}

t_intersections	get_sphere_intersections(t_object *sphere, t_ray ray)
{
	double					discriminant;
	t_tuple					sphere_to_ray;
	t_tuple					w_origin;
	t_double3				values;

	w_origin = create_tuple(0, 0, 0, 1);
	sphere_to_ray = ft_sub_tuples(ray.origin, w_origin);
	values.a = ft_tuple_scalarproduct(ray.direction, ray.direction);
	values.b = 2 * ft_tuple_scalarproduct(ray.direction, sphere_to_ray);
	values.c = ft_tuple_scalarproduct(sphere_to_ray, sphere_to_ray) - 1;
	discriminant = powf(values.b, 2) - (4 * values.a * values.c);
	return (compute_sphere_intersections(sphere, discriminant, values));
}
