/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:09:02 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/28 15:50:29 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
#define MINIRT_H

/* our headers */
# include "tools.h"
# include "typedefs.h"

/* libs headers */
# include "mlx.h"
# include "mlx_int.h"
# include <stdio.h>
# include <math.h>
# include <sys/time.h>

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

// reflection.c
t_tuple	ft_reflect_in(t_tuple in, t_tuple normal);

// lights.c
t_point_light	ft_create_point_light(t_color intensity, t_tuple position);
t_color			get_lighted_color(t_material mat, t_point_light light, t_tuple point, t_tuple eyev, t_tuple normalv);


/* ---------------------------------------------------------------------TUPLE */

// vector_operations.c
t_tuple	ft_create_tuple(double x, double y, double z, double w);
t_tuple	ft_add_tuples(t_tuple a, t_tuple b);
t_tuple	ft_sub_tuples(t_tuple a, t_tuple b);
t_tuple	ft_scale_tuple(t_tuple a, double scale);
t_tuple	ft_neg_tuple(t_tuple a);
double	ft_tuple_len(t_tuple a);
t_tuple	ft_normalize_tuple(t_tuple a);
double	ft_tuple_scalarproduct(t_tuple a, t_tuple b);
t_tuple	ft_multiply_tuples(t_tuple a, t_tuple b);
t_tuple	ft_multiply_tuple_by_matrix(t_tuple tuple, t_matrix4 m);
t_tuple	ft_multiply_matrix_by_tuple(t_matrix4 m, t_tuple tuple);
t_tuple	ft_multiply_tuple_by_double(t_tuple tuple, double c);

// color_operations.c
t_color	ft_create_color(double red, double green, double blue);
t_color	ft_add_colors(t_color a, t_color b);
t_color	ft_sub_colors(t_color a, t_color b);
t_color	ft_scale_color(t_color a, double scale);
t_color	ft_multiply_colors(t_color a, t_color b);
int		ft_convert_prime_color_to_int(double prime_color);
long	ft_convert_color_to_longint(t_color rgb);

/*-------------------------------------------------------------------- matrix */

/* matrix_utils.c */
t_matrix4	ft_create_matrix(void);
t_matrix4	ft_get_identity_matrix(void);

/* matrix_operations.c */
t_matrix4	ft_transpose_matrix(t_matrix4 matrix);
t_matrix4	ft_inverse_matrix(t_matrix4 m);
t_matrix4	ft_multiply_matrices(t_matrix4 m4_1, t_matrix4 m4_2);

/* sub_matrix_getter.c */
t_matrix3	ft_sub_m4tom3(t_matrix4 m4, int row, int column);
t_matrix2	ft_sub_m3tom2(t_matrix3 m3, int row, int column);

/* inverse_matrix_utils.c */
double			ft_calculate_m2_determinant(t_matrix2 m2);
double			ft_calculate_m3_determinant(t_matrix3 m3);
double			ft_calculate_m4_determinant(t_matrix4 m4);
double			ft_calculate_m3_cofactor(t_matrix3 m3, int i, int j);
double			ft_calculate_m4_cofactor(t_matrix4 m4, int i, int j);

/* inverse_matrix_utils_2.c */
t_matrix4		ft_apply_cofactors_to_matrix(t_matrix4 m);
t_matrix4		ft_apply_determinant_division_to_matrix(t_matrix4 m, double det);
bool			ft_is_matrix_invertible(t_matrix4 m);

/* init_tools.c */
t_counter3		init_counter3(void);
t_counter4		init_counter4(void);

/* transform_matrix.c */
t_matrix4		ft_calculate_translation_matrix(double x, double y, double z);
t_matrix4		ft_calculate_scaling_matrix(double x, double y, double z);
t_matrix4		ft_calculate_rotation_x_matrix(double radian);
t_matrix4		ft_calculate_rotation_y_matrix(double radian);
t_matrix4		ft_calculate_rotation_z_matrix(double radian);
t_matrix4		ft_calculate_shearing_matrix(t_shearing_values values);


/* ray_utils.c */
t_ray			ft_create_ray(t_tuple origin, t_tuple direction);
t_tuple			ft_calculate_new_point_on_ray(t_ray ray, double t);
t_intersections	ft_get_sphere_intersections(t_object *sphere, t_ray ray);
t_intersections	init_intersections(void);
t_intersections	calculate_sphere_intersections(double discr, t_double3 values);
t_ray			transform_ray_by_matrix(t_ray ray, t_matrix4 m);

/* hit.c */
t_hit			find_hit(t_intersections intersections);


/* object_utils.c */
t_object		*ft_create_sphere(t_data *data, t_tuple origin, int radius);
t_tuple			sphere_normal_at(t_object sphere, t_tuple world_point);



// print.c
void			ft_print_tuple(char *tuple_name, t_tuple tuple);
void			ft_print_color(char *color_name, t_color color);
void			ft_print_matrix4(t_matrix4 m4);
void			ft_print_matrix3(t_matrix3 m3);
void			ft_print_matrix2(t_matrix2 m2);
void			ft_print_ray(t_ray ray);
void			print_bits_of_long(long num);

#endif
