/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:09:02 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/30 15:53:29 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
#define MINIRT_H

/* libs */
# include "mlx.h"
# include "mlx_int.h"
# include <stdio.h>
# include <math.h>
# include <sys/time.h>
# include <stdbool.h>

# include "libft.h"
# include "tools_typedefs.h"
# include "typedefs.h"

/* includes/sub_includes */
# include "matrices.h"
# include "objects.h"
# include "ray_tracing.h"
# include "utils.h"
# include "scene.h"
# include "tools.h"
# include "tuples.h"


# define EPSILON 0.00001

# define UNDEFINED_TYPE 100
# define SPHERE_TYPE 101

# define NO_ERR 0
# define MALLOC_ERR -1

// utils.c
bool	ft_doublecmp(double a, double b);
bool	ft_tuplescmp(t_tuple a, t_tuple b);

// mlx
int		handle_key_event(int keycode);


/* ------------------------------------------------------------------RENDERER */

// canvas.c
void	my_mlx_pixel_put(t_image *image, int x, int y, long color);

// lights.c
t_point_light	ft_create_point_light(t_color intensity, t_tuple position);
t_color			get_lighted_color(t_material mat, t_point_light light, t_tuple point, t_tuple eyev, t_tuple normalv);


/* ---------------------------------------------------------------------TUPLE */


/* ray_utils.c */
t_ray			ft_create_ray(t_tuple origin, t_tuple direction);
t_tuple			compute_new_point_on_ray(t_ray ray, double t);
t_intersections	ft_get_sphere_intersections(t_object *sphere, t_ray ray);
t_intersections	init_intersections(void);
t_intersections	compute_sphere_intersections(double discr, t_double3 values);
t_ray			transform_ray_by_matrix(t_ray ray, t_matrix4 m);

/* hit.c */
t_hit			find_hit(t_intersections intersections);


/* object_utils.c */
t_object		*ft_create_sphere(t_data *data, t_tuple origin, int radius);
t_tuple			sphere_normal_at(t_object sphere, t_tuple world_point);

/* ---------------------------------------------------------------------WORLD */

// print.c
void			ft_print_tuple(char *tuple_name, t_tuple tuple);
void			ft_print_color(char *color_name, t_color color);
void			ft_print_matrix4(t_matrix4 m4);
void			ft_print_matrix3(t_matrix3 m3);
void			ft_print_matrix2(t_matrix2 m2);
void			ft_print_ray(t_ray ray);
void			print_bits_of_long(long num);

#endif
