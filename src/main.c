/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:37:48 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/19 18:30:57 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{	
	t_data	*data;
	t_tuple	from;
	t_tuple	to;
	t_tuple	up;
 	t_object			*s1;
	t_object			*s2;
	t_object			*c1;
	t_object			*p1;
	t_object			*cy1;
	t_object			*co1;
	t_point_light		*light;

	data = init_data();
	// data->mlx_data = start_mlx();

	// create_camera(data, CANVAS_X, CANVAS_Y, M_PI/2);
	// from = create_tuple(0, 3, -3, 1);
	// to = create_tuple(0, 1.5, 0, 1);
	// up = create_tuple(0, 1, 0, 0);
	// data->world->camera->transform_m = compute_view_transform_m(from, to, up);
	// data->world->view_transform_m = compute_view_transform_m(from, to, up);

	// light = create_point_light(data, create_color(1, 1, 1), create_tuple(10, 10, -10, 1));

	// cy1 = create_cylinder(data, create_tuple(0, 0, 0, 1), 1);
	
	// s1 = create_sphere(data, create_tuple(0, 0, 0, 1), 1);
	// s1->material.pattern = create_checker_pattern(create_color(0,0,0), create_color(1,1,1));
	// s1->material.texture_type = PATTERN_TEXTURE_TYPE;
	// s1->material.pattern.transform_m = ft_multiply_matrices(s1->material.pattern.transform_m, compute_scaling_matrix(0.3, 0.3, 0.3));
	// s1->material.pattern.transform_m = ft_multiply_matrices(s1->material.pattern.transform_m, compute_rotation_z_matrix(M_PI / 4));
	// s1->transform_m = ft_multiply_matrices(s1->transform_m, compute_translation_matrix(0, 1, 0));
	// s1->transform_m = ft_multiply_matrices(s1->transform_m, compute_scaling_matrix(3, 3, 3));
	// s1->material.color = create_color(1, 0, 0);


	// s2 = create_sphere(data, create_tuple(0, 0, 0, 1), 1);
	// s2->transform_m = ft_multiply_matrices(s2->transform_m, compute_translation_matrix(3, 0, 0));
	// s2->transform_m = ft_multiply_matrices(s2->transform_m, compute_scaling_matrix(2, 2, 2));
	// s2->material.color = create_color(0.2, 0.2, 0.2);

	// s2->material.pattern = create_checker_pattern(create_color(0,0,0), create_color(1,1,1));
	// s2->material.texture_type = PATTERN_TEXTURE_TYPE;

	// c1 = create_cube(data);
	// c1->transform_m = ft_multiply_matrices(c1->transform_m, compute_rotation_y_matrix(M_PI/4));
	// c1->material.color = create_color(1, 0, 1);
	// c1->transform_m = ft_multiply_matrices(c1->transform_m, compute_translation_matrix(-10, 1, 0));

	// p1 = create_plane(data);
	// p1->transform_m = ft_multiply_matrices(p1->transform_m, compute_rotation_x_matrix(M_PI/2));
	// p1->transform_m = ft_multiply_matrices(p1->transform_m, compute_translation_matrix(0, 0, -5));
	// p1->material.color = create_color(1, 1, 0.2);


	// render(data, data->world->camera, data->world);

	// mlx_put_image_to_window(data->mlx_data->mlx, data->mlx_data->win,
	// 	data->mlx_data->image.img, 0, 0);
	// my_mlx_pixel_put(&data->mlx_data->image, 340, 121, 0xffffff00);
	// printf("IMAGE DISPLAYED ------------------------------------------------------------------------------------\n");
	// mlx_loop(data->mlx_data->mlx);





	t_ray		ray;

	co1 = create_cone(data, create_tuple(0, 0, 0, 1), 1);
	ray = ft_create_ray(create_tuple(1, 1, -5, 1), create_tuple(-0.5, -1, 1, 0));
	ray.direction = ft_normalize_tuple(ray.direction);
	print_intersection(get_cone_intersections(co1, ray));
	// ft_print_tuple("normal_at", cylinder_normal_at(cy1, create_tuple(-1, 1, 0, 1)));

	return (0);
}
