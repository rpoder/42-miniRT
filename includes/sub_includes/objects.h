/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margot <margot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:09:51 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/03 16:56:59 by margot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* object_intersections */
t_intersections	init_intersections(t_object *object);
t_intersections	get_sphere_intersections(t_object *sphere, t_ray ray);

/* sphere.c------------------------------------------------------------------ */
static t_matrix4	compute_parsing_sphere_transform_m(t_tuple origin, int radius);
t_object			*create_sphere(t_data *data, t_tuple origin, int radius);
t_tuple				sphere_normal_at(t_object *sphere, t_tuple world_point);

/* material.c */
t_material	get_default_material(void);