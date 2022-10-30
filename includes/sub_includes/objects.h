/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:09:51 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/30 14:14:35 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* sphere.c------------------------------------------------------------------ */
t_object		*ft_create_sphere(t_data *data, t_tuple origin, int radius);
t_tuple			sphere_normal_at(t_object sphere, t_tuple world_point);
t_intersections	compute_sphere_intersections(double discr, t_double3 values);
t_intersections	ft_get_sphere_intersections(t_object *sphere, t_ray ray);
