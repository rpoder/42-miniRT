/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:09:51 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/25 19:50:37 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ----------------------------------------------------------------------CUBE */
/* create_cube.c------------------------------------------------------------- */
t_object			*create_cube(t_data *data);
/* cube_normal_and_intersections--------------------------------------------- */
t_tuple				get_cube_normal_at(t_object *cube, t_tuple point);
t_intersections		get_cube_intersections(t_object *cube, t_ray ray);

/* ----------------------------------------------------------------------CONE */
/* create_cone.c------------------------------------------------------------- */
t_object			*create_cone(t_data *data, t_tuple origin, double radius);
/* cone_intersections.c------------------------------------------------------ */
t_intersections		get_cone_intersections(t_object *cone, t_ray ray);
/* cone_normal.c------------------------------------------------------------- */
t_tuple				cone_normal_at(t_object *cone, t_tuple object_point);

/* --------------------------------------------------------------------PLANE */
/* create_plane.c----------------------------------------------------------- */
t_object			*create_plane(t_data *data, t_parsing_values_tool values);
/* plane_normal_and_intersections------------------------------------------- */
t_tuple				get_plane_normal_at(void);
t_intersections		get_plane_intersections(t_object *plane, t_ray ray);


/* --------------------------------------------------------------------SPHERE */
/* create_sphere.c----------------------------------------------------------- */
t_object			*create_sphere(t_data *data, t_parsing_values_tool values);
/* sphere_normal_and_intersections------------------------------------------- */
t_intersections		get_sphere_intersections(t_object *sphere, t_ray ray);
t_tuple				get_sphere_normal_at(t_object *sphere, t_tuple object_point);

/* ------------------------------------------------------------------CYLINDER */
/* create_cylinder.c--------------------------------------------------------- */
t_object			*create_cylinder(t_data *data, t_parsing_values_tool values);
/* cylinder_normal.---------------------------------------------------------- */
t_tuple				get_cylinder_normal_at(t_object *cylinder, t_tuple object_point);
/* cylinder_intersections */
t_intersections		get_cylinder_caps_intersections(t_object *cylinder, t_ray ray, t_intersections intersections);
t_intersections		get_cylinder_intersections(t_object *cylinder, t_ray ray);

/* -----------------------------------------------------------ABSTRACT_OBJECT */
/* abstract_object_intersections--------------------------------------------- */
t_intersections		get_object_intersections(t_object *object, t_ray ray);
t_intersections		init_intersections(t_object *object);
/* abstract_object_normal---------------------------------------------------- */
t_tuple				get_object_normal_at(t_object *object, t_tuple world_point);
/* material.c ----------------------------------------------------------------*/
t_material			get_default_material(void);
