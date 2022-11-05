/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:37:48 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/04 12:15:03 by mpourrey         ###   ########.fr       */
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

	data = init_data();

	t_tuple	from = create_tuple(1, 3, 2, 1);
	t_tuple	to = create_tuple(4, -2, 8, 1);
	t_tuple	up = create_tuple(1, 1, 0, 0);
	
	data->world->view_transform_m = compute_view_transform_m(from, to, up);
	//data->mlx_data = start_mlx();

	/* TESTS */
/* 	t_object			*s1;
	t_object			*s2;
	t_point_light		*light;
	t_ray				ray;
	t_w_intersections	w_intersections;
	t_pcomp_tool		tool;

	light = create_point_light(data, create_color(1, 1, 1), create_tuple(-10, 10, -10, 1));
	s1 = create_sphere(data, create_tuple(0, 0, 0, 1), 1);
	s1->material.color = create_color(0.8, 1.0, 0.6);
	s1->material.diffuse = 0.7;
	s1->material.specular = 0.2;
	s2 = create_sphere(data, create_tuple(0, 0, 0, 1), 1);
	s2->transform_m = ft_multiply_matrices(s2->transform_m, compute_scaling_matrix(0.5, 0.5, 0.5));

	/* CAMERA */
	ray = ft_create_ray(create_tuple(0, 0, -5, 1), create_tuple(0, 0, 1, 0));
	ft_print_color("final_color", get_color_on_ray(*data->world, ray)); */
	
	
	// /* DISPLAY */
	// t_intersections			sphere_intersects;
	// t_hit					hit;
	// int						win_x;
	// int						win_y;
	// double					ray_y;
	// double					ray_x;
	// t_tuple					point;
	// // double					intersections[100];

	// win_y = 0;
	// win_x = 0;
	// ray_y = 2;
	// ray_x = -2;

	// while (win_x < 1000)
	// {
	// 	ray_x = ray_x + (1.0 / 250.0);
	// 	win_y = 0;
	// 	ray_y = 2;
	// 	while(win_y < 1000)
	// 	{
	// 		ray_y = ray_y - (1.0 / 250.0);
	// 		ray.direction = create_tuple(ray_x, ray_y, 5, 0);
	// 		ray.direction = ft_normalize_tuple(ray.direction);
	// 		sphere_intersects = get_sphere_intersections(s1, ray);

	// 		hit = find_hit(sphere_intersects);
	// 		if (hit.does_hit == true)
	// 		{
	// 			point = compute_new_point_on_ray(ray, hit.i);
	// 			normalv = sphere_normal_at(s1, point);
	// 			eyev = ft_neg_tuple(ray.direction);
	// 			res = get_lighted_color(s1->material, *light, point, ft_normalize_tuple(eyev), ft_normalize_tuple(normalv));

	// 			// my_mlx_pixel_put(&data->mlx_data->image, win_x, win_y, 0x00ffff00);
	// 			my_mlx_pixel_put(&data->mlx_data->image, win_x, win_y, ft_convert_color_to_longint(res));

	// 		}
	// 		win_y++;
	// 	}
	// 	win_x++;
	// }
	// mlx_put_image_to_window(data->mlx_data->mlx, data->mlx_data->win, data->mlx_data->image.img, 0, 0);
	// printf("------------------------------------------------------------------------IMAGE DISPLAYED\n");
	// mlx_loop(data->mlx_data->mlx);

}


