/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:21:18 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/30 17:38:57 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_TRACING_H
# define RAY_TRACING_H

/* get_color_on_ray.c --------------------------------------------------------*/
t_color				get_color_on_ray(t_world world, t_ray ray);

/* get_lighted_color--------------------------------------------------------- */
t_color				get_lighted_color(t_world world, t_point_light *light,
						t_ray_pcomp_tool pcomp);

/* ray.c----------------------------------------------------------------------*/
t_ray				create_ray(t_tuple origin, t_tuple direction);
t_tuple				compute_new_point_on_normalized_ray(t_ray ray, double t);
t_tuple				compute_new_point_on_ray(t_ray ray, double t);
t_ray				transform_ray_by_matrix(t_ray ray, t_matrix4 m);

/* renderer.c---------------------------------------------------------------- */
void				render(t_data *data, t_camera *camera, t_world *world);

/* world_intersections------------------------------------------------------- */
t_w_intersections	get_world_intersections(t_world world, t_ray ray);
t_hit				find_w_hit(t_w_intersections w_intersections);

#endif