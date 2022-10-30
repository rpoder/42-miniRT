/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:29:26 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/30 19:48:49 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* lights.c------------------------------------------------------------------ */
t_point_light	*create_point_light(t_data *data, t_color intensity, t_tuple pos);
static			t_tuple	ft_reflect_in(t_tuple in, t_tuple normal);
t_color			get_lighted_color(t_material mat, t_point_light light, t_tuple point, t_tuple eyev, t_tuple normalv);

/* camera.c */
t_ray_precompute_tool precompute_ray(t_w_intersections w_intersections, t_ray ray);
