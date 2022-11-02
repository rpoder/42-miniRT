/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ronanpoder <ronanpoder@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:29:26 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/02 12:05:28 by ronanpoder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* lights.c------------------------------------------------------------------ */
t_point_light	*create_point_light(t_data *data, t_color intensity, t_tuple pos);
static			t_tuple	ft_reflect_in(t_tuple in, t_tuple normal);
t_color			get_lighted_color(t_world world, t_pcomp_tool pcomp);

/* camera.c */
t_pcomp_tool precompute_ray(t_w_intersections w_intersections, t_ray ray);
