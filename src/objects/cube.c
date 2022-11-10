/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:40:19 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/10 15:36:43 by mpourrey         ###   ########.fr       */
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
	node = ft_lstnew(new_cube);
	if (!node)
	{
		free(new_cube);
		return (NULL);
	}
	ft_lstadd_back(&data->world->objects, node);
	return (new_cube);
}

static t_cube_faces_intersections	check_axis(double origin, double direction)
{
	t_cube_faces_intersections	faces_intersections;
	double						t_min_numerator;
	double						t_max_numerator;
	double						tmp;

	t_min_numerator = (-1.0 - origin);
	t_min_numerator = (1.0 - origin);
	printf("fabs = %f\n", fabs(direction));
	if (fabs(direction) >= EPSILON)
	{
		faces_intersections.t_min = t_min_numerator / direction;
		faces_intersections.t_max = t_max_numerator / direction;
	}
	else
	{
		printf("infinite\n");
		faces_intersections.t_min = t_min_numerator * INFINITY;
		faces_intersections.t_max = t_max_numerator * INFINITY;
	}
	if (faces_intersections.t_min > faces_intersections.t_max)
	{
		tmp = faces_intersections.t_min;
		faces_intersections.t_min = faces_intersections.t_max;
		faces_intersections.t_max = tmp;
	}
	printf("faces_intersections.t1 = %f\n", faces_intersections.t_min);
	printf("faces_intersections.t2 = %f\n", faces_intersections.t_max);
	return (faces_intersections);
}

static	double get_min(double a, double b, double c)
{
	if (a <= b && a <= c)
		return (a);
	else if (b <= a && b <= c)
		return (b);
	else
		return (c);
}

static	double get_max(double a, double b, double c)
{
	if (a >= b && a >= c)
		return (a);
	else if (b >= a && b >= c)
		return (b);
	else
		return (c);
}

t_intersections	get_cube_intersections(t_object *cube, t_ray ray)
{
	t_intersections				cube_intersections;
	t_cube_faces_intersections	faces_intersections_x;
	t_cube_faces_intersections	faces_intersections_y;
	t_cube_faces_intersections	faces_intersections_z;

	faces_intersections_x = check_axis(ray.origin.x, ray.direction.x);
	faces_intersections_y = check_axis(ray.origin.y, ray.direction.y);
	faces_intersections_z = check_axis(ray.origin.z, ray.direction.z);

	cube_intersections.i1 = get_max(faces_intersections_x.t_min, faces_intersections_y.t_min, faces_intersections_z.t_min);
	cube_intersections.i2 = get_min(faces_intersections_x.t_max, faces_intersections_y.t_max, faces_intersections_z.t_max);
	cube_intersections.nb_of_intersections = 2;
	cube_intersections.object = cube;
	return (cube_intersections);
}

