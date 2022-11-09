/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ronanpoder <ronanpoder@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:09:51 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/09 16:08:52 by ronanpoder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* object_intersections */
t_intersections		init_intersections(t_object *object);
t_intersections		get_object_intersections(t_object *obj, t_ray ray);
t_tuple				normal_at(t_object *object, t_tuple world_point);

/* sphere.c------------------------------------------------------------------ */
static t_matrix4	compute_parsing_sphere_transform_m(t_tuple origin, int radius);
t_object			*create_sphere(t_data *data, t_tuple origin, int radius);
t_intersections		get_sphere_intersections(t_object *sphere, t_ray ray);
t_tuple				sphere_normal_at(t_object *sphere, t_tuple object_point);

/* plane.c------------------------------------------------------------------- */
t_object			*create_plane(t_data *data);
t_tuple				plane_normal_at(void);
t_intersections		get_plane_intersections(t_object *plane, t_ray ray);

/* material.c ----------------------------------------------------------------*/
t_material			get_default_material(void);

/* objects.c -----------------------------------------------------------------*/
void				set_transform(t_object *obj, t_matrix4 transform_to_apply);
