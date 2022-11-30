/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:15:58 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/30 16:47:31 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

static t_tuple	compute_up(t_tuple to, t_camera_values_tool values)
{
	t_tuple	tmp;
	double	tmp_coord;
	t_tuple	up;

	tmp = cross_product(create_tuple(0, 1, 0, 0), normalize_tuple(to));
	tmp_coord = tmp.x;
	tmp.x = tmp.z;
	tmp.z = tmp_coord;
	if (dot_product(create_tuple(0, 0, 1, 0),
			normalize_tuple(values.orientation_vector)) >= 0.0)
		tmp = ft_neg_tuple(tmp);
	up = normalize_tuple(cross_product(values.orientation_vector, tmp));
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
	to = ft_add_tuples(values.origin, values.orientation_vector);
	if (to.x == 0.0)
		to.x = EPSILON;
	up = compute_up(to, values);
	data->world->camera->transform_m = compute_view_transform_m(values.origin,
			to, up);
	return (data->world->camera);
}
