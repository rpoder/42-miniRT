/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ronanpoder <ronanpoder@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:21:18 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/09 12:32:34 by ronanpoder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* get_color_on_ray.c */
t_color	get_color_on_ray(t_world world, t_ray ray);
t_w_intersections	compute_world_intersections(t_world world, t_ray ray);
t_hit	find_w_hit(t_w_intersections w_intersections);

/* get_lighted_color.c */
t_color	get_lighted_color(t_world world, t_pcomp_tool pcomp);
bool	is_in_shadow(t_world world, t_tuple point);

/* ray.c */
t_ray	ft_create_ray(t_tuple origin, t_tuple direction);
t_tuple	compute_new_point_on_ray(t_ray ray, double t);
t_ray	transform_ray_by_matrix(t_ray ray, t_matrix4 m);
