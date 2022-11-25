/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:29:26 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/25 16:33:48 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* point_lights.c------------------------------------------------------------ */
t_point_light	*create_point_light(t_data *data, t_color intensity, t_tuple pos);

/* camera.c-------------------------------------------------------------------*/
t_camera	*create_camera(t_data *data, int x_size, int y_size, t_parsing_values_tool values);
t_matrix4		 compute_view_transform_m(t_tuple from, t_tuple to, t_tuple up);

/* renderer.c---------------------------------------------------------------- */
void			render(t_data *data, t_camera *camera, t_world *world);