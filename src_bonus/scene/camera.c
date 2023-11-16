/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:15:58 by rpoder            #+#    #+#             */
/*   Updated: 2022/12/02 13:12:04 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_matrix4	compute_view_orientation_matrix(t_tuple leftv,
	t_tuple true_upv, t_tuple forwardv, t_tuple from)
{
	t_matrix4	orientation_m;
	t_matrix4	translation_m;

	orientation_m = get_identity_matrix();
	orientation_m.matrix[0][0] = leftv.x;
	orientation_m.matrix[0][1] = leftv.y;
	orientation_m.matrix[0][2] = leftv.z;
	orientation_m.matrix[1][0] = true_upv.x;
	orientation_m.matrix[1][1] = true_upv.y;
	orientation_m.matrix[1][2] = true_upv.z;
	orientation_m.matrix[2][0] = -forwardv.x;
	orientation_m.matrix[2][1] = -forwardv.y;
	orientation_m.matrix[2][2] = -forwardv.z;
	translation_m = compute_translation_matrix(-from.x, -from.y, -from.z);
	return (multiply_matrices(orientation_m, translation_m));
}

static t_matrix4	compute_view_transform_m(t_tuple from, t_tuple to,
		t_tuple up)
{
	t_matrix4	view_transform_m;
	t_tuple		forwardv;
	t_tuple		leftv;
	t_tuple		true_upv;

	forwardv = normalize_tuple(sub_tuples(to, from));
	leftv = cross_product(forwardv, normalize_tuple(up));
	true_upv = cross_product(leftv, forwardv);
	view_transform_m = compute_view_orientation_matrix(leftv, true_upv,
			forwardv, from);
	return (view_transform_m);
}

static double	compute_pixel_size(t_camera *camera, int hsize, int vsize,
	double fov)
{
	double		half_fov;
	double		aspect;

	half_fov = tan(fov / 2.0);
	aspect = (double)hsize / (double)vsize;
	if (aspect >= 1)
	{
		camera->half_width = half_fov;
		camera->half_height = half_fov / aspect;
	}
	else
	{
		camera->half_width = half_fov * aspect;
		camera->half_height = half_fov;
	}
	return ((camera->half_width * 2) / (double)hsize);
}

static t_tuple	compute_up(t_camera_values_tool values)
{
	t_tuple	tmp;
	t_tuple	up;

	tmp = cross_product(create_tuple(0, 1, 0, 0),
			normalize_tuple(values.orientation_vector));
	up = normalize_tuple(cross_product(
				normalize_tuple(values.orientation_vector), tmp));
	return (up);
}

t_camera	*create_camera(t_data *data, int hsize, int vsize,
		t_camera_values_tool values)
{
	t_tuple	to;
	t_tuple	up;

	data->world->camera = malloc(sizeof(t_camera));
	if (!data->world->camera)
		return (NULL);
	data->world->camera->vsize = vsize;
	data->world->camera->hsize = hsize;
	data->world->camera->fov = values.fov;
	data->world->camera->pixel_size = compute_pixel_size(data->world->camera,
			hsize, vsize, values.fov);
	to = add_tuples(values.origin, values.orientation_vector);
	if (values.orientation_vector.x == 0.0)
		values.orientation_vector.x = EPSILON;
	up = compute_up(values);
	data->world->camera->transform_m = compute_view_transform_m(values.origin,
			to, up);
	return (data->world->camera);
}
