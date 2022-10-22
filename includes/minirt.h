/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:09:02 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/22 19:06:24 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
#define MINIRT_H

# include "mlx.h"
# include "mlx_int.h"
# include <stdio.h>
# include <stdbool.h>
# include <math.h>
# include "tools.h"

# define EPSILON 0.00001

typedef struct	s_matrix4{
	float	matrix[4][4];
}	t_matrix4;

typedef struct	s_matrix3{
	float	matrix[3][3];
}	t_matrix3;

typedef struct	s_matrix2{
	float	matrix[2][2];
}	t_matrix2;

// typedef  float *matrix_ptr[4][4];

typedef struct	s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_mlx_data
{
	void		*mlx;
	void		*win;
	t_image		image;
}	t_mlx_data;

typedef struct s_tuple
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_tuple;

typedef struct s_color
{
	float	red;
	float	green;
	float	blue;
}	t_color;

// utils.c
bool	ft_floatcmp(float a, float b);
bool	ft_tuplescmp(t_tuple a, t_tuple b);

// mlx
void	my_mlx_pixel_put(t_image *data, int x, int y, int color);

// vector_operations.c
t_tuple	ft_create_tuple(float x, float y, float z, float w);
t_tuple	ft_add_tuples(t_tuple a, t_tuple b);
t_tuple	ft_sub_tuples(t_tuple a, t_tuple b);
t_tuple	ft_scale_tuple(t_tuple a, float scale);
t_tuple	ft_neg_tuple(t_tuple a);
float	ft_tuple_len(t_tuple a);
t_tuple	ft_normalize_tuple(t_tuple a);
float	ft_tuple_scalarproduct(t_tuple a, t_tuple b);
t_tuple	ft_multiply_tuples(t_tuple a, t_tuple b);
t_tuple	ft_multiply_tuple_by_matrix(t_tuple tuple, t_matrix4 m);

// color_operations.c
t_color	ft_create_color(float red, float green, float blue);
t_color	ft_add_colors(t_color a, t_color b);
t_color	ft_sub_colors(t_color a, t_color b);
t_color	ft_multiply_colors(t_color a, t_color b);

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
float		ft_calculate_m2_determinant(t_matrix2 m2);
float		ft_calculate_m3_determinant(t_matrix3 m3);
float		ft_calculate_m4_determinant(t_matrix4 m4);
float		ft_calculate_m3_cofactor(t_matrix3 m3, int i, int j);
float		ft_calculate_m4_cofactor(t_matrix4 m4, int i, int j);

/* inverse_matrix_utils_2.c */
t_matrix4	ft_apply_cofactors_to_matrix(t_matrix4 m);
t_matrix4	ft_apply_determinant_division_to_matrix(t_matrix4 m, float det);
bool		ft_is_matrix_invertible(t_matrix4 m);

/* init_tools.c */
t_counter3	init_counter3(void);
t_counter4	init_counter4(void);

/* transform_matrix.c */
t_matrix4	ft_get_translate_matrix(float x, float y, float z);
t_matrix4	ft_get_scale_matrix(float x, float y, float z);
t_matrix4	ft_get_rotate_x_matrix(float radian);
t_matrix4	ft_get_rotate_y_matrix(float radian);
t_matrix4	ft_get_rotate_z_matrix(float radian);
t_matrix4	ft_get_shear_matrix(t_shearing_values values);

// print.c
void	ft_print_tuple(char *tuple_name, t_tuple tuple);
void	ft_print_color(char *color_name, t_color color);
void	ft_print_matrix4(t_matrix4 m4);
void	ft_print_matrix3(t_matrix3 m3);
void	ft_print_matrix2(t_matrix2 m2);

#endif
