/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:01:36 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/30 20:34:14 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_matrix4	compute_parsing_sphere_transform_m(t_tuple origin, int radius)
{
	t_matrix4	t1;
	t_matrix4	t2;
	t_matrix4	transform_matrix;

	t1 = get_identity_matrix();
	if (origin.x != 0 || origin.y != 0 || origin.x != 0)
		t1 = compute_translation_matrix(origin.x, origin.y, origin.z);
	t2 = compute_scaling_matrix(radius, radius, radius);
	transform_matrix = ft_multiply_matrices(t1, t2);
	return (transform_matrix);
}

t_material	get_default_material(void)
{
	t_material	mat;

	mat.color = ft_create_color(1, 1, 1);
	mat.ambient = 0.1;
	mat.diffuse = 0.9;
	mat.specular = 1;
	mat.shininess = 200.0;
	return (mat);
}

t_object	*create_sphere(t_data *data, t_tuple origin, int radius)
{
	t_object	*new_sphere;
	t_list		*node;


	new_sphere = malloc(sizeof(t_object));
	if (!new_sphere)
		return (NULL);
	new_sphere->id = ft_lstlen(data->objects);

	new_sphere->transform_m = compute_parsing_sphere_transform_m(origin, radius);
	new_sphere->material = get_default_material();

	node = ft_lstnew(new_sphere);
	if (!node)
	{
		free(new_sphere);
		return (NULL);
	}
	ft_lstadd_back(&data->objects, node);
	return (new_sphere);
}

t_tuple	sphere_normal_at(t_object *sphere, t_tuple world_point)
{
	t_tuple	origin;
	t_tuple	object_point;
	t_tuple	world_normal;
	t_tuple	object_normal;
	t_matrix4	inv_matrix;
	t_matrix4	transposed_matrix;

	inv_matrix = ft_inverse_matrix(sphere->transform_m);
	object_point = ft_multiply_matrix_by_tuple(inv_matrix, world_point);
	origin = ft_create_tuple(0, 0, 0, 1);
	object_normal = ft_sub_tuples(object_point, origin);
	transposed_matrix = ft_transpose_matrix(inv_matrix);
	world_normal = ft_multiply_matrix_by_tuple(transposed_matrix, object_normal);
	world_normal.w = 0;
	world_normal = ft_normalize_tuple(world_normal);
	return (world_normal);
}

t_intersections	compute_sphere_intersections(double discr, t_double3 values)
{
	t_intersections	intersections;

	intersections = init_intersections();
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
	t_ray					ray2;

	ray2 = transform_ray_by_matrix(ray, ft_inverse_matrix(sphere->transform_m));
	w_origin = ft_create_tuple(0, 0, 0, 1);
	sphere_to_ray = ft_sub_tuples(ray2.origin, w_origin);
	values.a = ft_tuple_scalarproduct(ray2.direction, ray2.direction);
	values.b = 2 * ft_tuple_scalarproduct(ray2.direction, sphere_to_ray);
	values.c = ft_tuple_scalarproduct(sphere_to_ray, sphere_to_ray) - 1;
	discriminant = powf(values.b, 2) - (4 * values.a * values.c);
	return (compute_sphere_intersections(discriminant, values));
}
