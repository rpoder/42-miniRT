/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:45:57 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/30 17:52:55 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLES_H
# define TUPLES_H

/* color_operations.c --------------------------------------------------------*/
t_color	add_colors(t_color a, t_color b);
t_color	sub_colors(t_color a, t_color b);
t_color	scale_color(t_color a, double scale);
t_color	multiply_colors(t_color a, t_color b);

/* colors --------------------------------------------------------------------*/
t_color	create_color(double red, double green, double blue);
int		convert_prime_color_to_int(double prime_color);
long	convert_color_to_longint(t_color rgb);

/* vector.c ------------------------------------------------------------------*/
t_tuple	create_tuple(double x, double y, double z, double w);

/* vector_operations.c -------------------------------------------------------*/
t_tuple	add_tuples(t_tuple a, t_tuple b);
t_tuple	sub_tuples(t_tuple a, t_tuple b);
t_tuple	neg_tuple(t_tuple a);
t_tuple	scale_tuple(t_tuple a, double scale);
t_tuple	cross_product(t_tuple a, t_tuple b);

/* vector_multiplications.c --------------------------------------------------*/
t_tuple	multiply_tuple_by_matrix(t_tuple tuple, t_matrix4 m);
t_tuple	multiply_matrix_by_tuple(t_matrix4 m, t_tuple tuple);
t_tuple	multiply_tuple_by_double(t_tuple tuple, double c);

/* vector_utils-------------------------------------------------------------- */
t_tuple	normalize_tuple(t_tuple a);
double	dot_product(t_tuple a, t_tuple b);
double	tuple_len(t_tuple a);

#endif