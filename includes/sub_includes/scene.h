/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:29:26 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/07 15:07:53 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* lights.c------------------------------------------------------------------ */
t_point_light	*create_point_light(t_data *data, t_color intensity, t_tuple pos);
t_tuple			ft_reflect_in(t_tuple in, t_tuple normal);

/* camera.c ------------------------------------------------------------------*/
t_camera	*create_camera(t_data *data, int hsize, int vsize, double fov);
t_ray		ray_for_pixel(t_camera *camera, double canvas_x, double canvas_y);
void		render(t_data *data, t_camera *camera, t_world *world);

/* world ---------------------------------------------------------------------*/
t_matrix4 compute_view_transform_m(t_tuple from, t_tuple to, t_tuple up);
