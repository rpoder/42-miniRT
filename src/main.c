/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:37:48 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/10 13:26:38 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_hit	find_hit(t_intersections intersections)
{
	t_hit	hit;

	hit.object = intersections.object;
	if ((intersections.i1 < 0 && intersections.i2 < 0)
		|| intersections.nb_of_intersections == 0)
	{
		hit.does_hit = false;
		hit.i = 0;
	}
	else
	{
		hit.does_hit = true;
		if (intersections.i1 < 0)
			hit.i = intersections.i2;
		else if (intersections.i2 < 0)
			hit.i = intersections.i1;
		else if (intersections.i1 < intersections.i2)
			hit.i = intersections.i1;
		else
			hit.i = intersections.i2;
	}
	return (hit);
}


int	main(void)
{

	t_data	*data;
	t_ray	ray;
	t_tuple	from;
	t_tuple	to;
	t_tuple	up;
 	t_object			*s1;
	t_object			*s2;
	t_point_light		*light;

	data = init_data();
	data->mlx_data = start_mlx();

	create_camera(data, CANVAS_X, CANVAS_Y, M_PI/4);
	from = create_tuple(0, 0, -20, 1);
	to = create_tuple(0, 0, 0, 1);
	up = create_tuple(0, 1, 0, 0);
	data->world->camera->transform_m = compute_view_transform_m(from, to, up);
	data->world->view_transform_m = compute_view_transform_m(from, to, up);

	light = create_point_light(data, create_color(1, 1, 1), create_tuple(10, 10, -10, 1));

	s1 = create_sphere(data, create_tuple(0, 0, 0, 1), 1);
	s1->material.pattern = create_checker_pattern(create_color(0,0,0), create_color(1,1,1));
	s1->material.texture_type = PATTERN_TEXTURE_TYPE;
	s1->material.pattern.transform_m = ft_multiply_matrices(s1->material.pattern.transform_m, compute_scaling_matrix(0.3, 0.3, 0.3));
	s1->material.pattern.transform_m = ft_multiply_matrices(s1->material.pattern.transform_m, compute_rotation_z_matrix(M_PI / 4));
	s1->transform_m = ft_multiply_matrices(s1->transform_m, compute_translation_matrix(0, 1, 0));
	s1->transform_m = ft_multiply_matrices(s1->transform_m, compute_scaling_matrix(3, 3, 3));

	s2 = create_sphere(data, create_tuple(0, 0, 0, 1), 1);
	s2->transform_m = ft_multiply_matrices(s2->transform_m, compute_translation_matrix(3, 0, 0));
	s2->transform_m = ft_multiply_matrices(s2->transform_m, compute_scaling_matrix(3, 3, 3));
	s2->material.pattern = create_checker_pattern(create_color(0,0,0), create_color(1,1,1));
	s2->material.texture_type = PATTERN_TEXTURE_TYPE;

	render(data, data->world->camera, data->world);

	mlx_put_image_to_window(data->mlx_data->mlx, data->mlx_data->win,
		data->mlx_data->image.img, 0, 0);
	printf("IMAGE DISPLAYED ------------------------------------------------------------------------------------\n");
	mlx_loop(data->mlx_data->mlx);

}
