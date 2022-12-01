/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:09:51 by rpoder            #+#    #+#             */
/*   Updated: 2022/12/01 01:28:05 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

/* -----------------------------------------------------------ABSTRACT_OBJECT */
/* abstract_object_intersections */
t_intersections		get_object_intersections(t_object *object, t_ray ray);
t_intersections		init_intersections(t_object *object);
/* abstract_object_normal */
t_tuple				get_object_normal_at(t_object *object, t_tuple world_point);
/* material.c */
t_material			get_default_material(void);
/* transform_abstract_object */
t_matrix4			translate_and_scale_object(t_tuple origin, double radius);
t_matrix4			orient_object(t_object *object, t_tuple orientation);

/* ----------------------------------------------------------------------CONE */
/* create_cone.c */
t_object			*create_cone(t_data *data, t_cone_values_tool values);
/* cone_intersections.c */
t_intersections		get_cone_intersections(t_object *cone, t_ray ray);
/* cone_normal.c */
t_tuple				get_cone_normal_at(t_object *cone, t_tuple object_point);
/* cone_caps.c */
t_intersections		get_cone_caps_intersections(t_object *cone,
						t_ray ray, t_intersections intersections);

/* ----------------------------------------------------------------------CUBE */
/* create_cube.c */
t_object			*create_cube(t_data *data, t_cube_values_tool values);
/* cube_normal_and_intersections */
t_tuple				get_cube_normal_at(t_tuple point);
t_intersections		get_cube_intersections(t_object *cube, t_ray ray);

/* ------------------------------------------------------------------CYLINDER */
/* create_cylinder.c */
t_object			*create_cylinder(t_data *data,
						t_cylinder_values_tool values);
/* cylinder_normal.c */
t_tuple				get_cylinder_normal_at(t_object *obj, t_tuple object_point);
/* cylinder_intersections */
t_intersections		get_cylinder_caps_intersections(t_object *cylinder,
						t_ray ray, t_intersections intersections);
t_intersections		get_cylinder_intersections(t_object *cylinder, t_ray ray);

/* ---------------------------------------------------------------------PLANE */
/* create_plane.c */
t_object			*create_plane(t_data *data, t_plane_values_tool values);
/* plane_normal_and_intersections.c*/
t_tuple				get_plane_normal_at(void);
t_intersections		get_plane_intersections(t_object *plane, t_ray ray);

/* --------------------------------------------------------------------SPHERE */
/* create_sphere.c */
t_object			*create_sphere(t_data *data, t_sphere_values_tool values);
/* sphere_normal_and_in */
t_intersections		get_sphere_intersections(t_object *sphere, t_ray ray);
t_tuple				get_sphere_normal_at(t_tuple object_point);

/* ------------------------------------------------------------------TRIANGLE */
/* create_triangle.c */
t_object			*create_triangle(t_data *data,
						t_triangle_values_tool values);
/* triangle_normal and intersections.c */
t_tuple				get_triangle_normal_at(t_object *triangle);
t_intersections		get_triangle_intersections(t_object *triangle, t_ray ray);

#endif
