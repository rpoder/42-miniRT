/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 13:28:21 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/27 23:16:01 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* cofactor.c---------------------------------------------------------------- */
double		compute_m3_cofactor(t_matrix3 m3, int i, int j);
double		compute_m4_cofactor(t_matrix4 m4, int i, int j);
t_matrix4	apply_cofactors_to_matrix(t_matrix4 m);

/* compute_transform_matrix.c------------------------------------------------ */
t_matrix4	compute_translation_matrix(double x, double y, double z);
t_matrix4	compute_scaling_matrix(double x, double y, double z);
t_matrix4	compute_shearing_matrix(t_shearing_values values);

/* compute_transform_matrix_2.c---------------------------------------------- */
t_matrix4	compute_rotation_x_matrix(double radian);
t_matrix4	compute_rotation_y_matrix(double radian);
t_matrix4	compute_rotation_z_matrix(double radian);

/* determinant.c------------------------------------------------------------- */
double		compute_m2_determinant(t_matrix2 m2);
double		compute_m3_determinant(t_matrix3 m3);
double		compute_m4_determinant(t_matrix4 m4);
t_matrix4	apply_determinant_division_to_matrix(t_matrix4 m, double det);

/* matrix_operations.c------------------------------------------------------- */
t_matrix4	ft_transpose_matrix(t_matrix4 m4);
t_matrix4	multiply_matrices(t_matrix4 m4_1, t_matrix4 m4_2);
t_matrix4	ft_inverse_matrix(t_matrix4 m);

/* matrix_utils.c------------------------------------------------------------ */
t_matrix4	get_identity_matrix(void);
bool		is_matrix_invertible(t_matrix4 m);
t_matrix4	m4_bzero(void);

/* sub_matrix.c-------------------------------------------------------------- */
t_matrix3	sub_m4tom3(t_matrix4 m4, int row, int column);
t_matrix2	sub_m3tom2(t_matrix3 m3, int row, int column);
