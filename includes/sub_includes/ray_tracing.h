/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:21:18 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/30 18:49:33 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* intersections.c----------------------------------------------------------- */
t_w_intersections	compute_world_intersections(t_data *data, t_ray ray);
t_intersections		init_intersections(void);
t_hit				find_hit(t_intersections intersections);

/* ray.c--------------------------------------------------------------------- */
t_ray				ft_create_ray(t_tuple origin, t_tuple direction);
t_tuple				compute_new_point_on_ray(t_ray ray, double t);
t_ray				transform_ray_by_matrix(t_ray ray, t_matrix4 m);
