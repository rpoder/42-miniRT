/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margot <margot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:45:57 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/03 12:14:10 by margot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* color_operations.c --------------------------------------------------------*/
t_color	ft_add_colors(t_color a, t_color b);
t_color	ft_sub_colors(t_color a, t_color b);
t_color	ft_scale_color(t_color a, double scale);
t_color	ft_multiply_colors(t_color a, t_color b);

/* colors --------------------------------------------------------------------*/
t_color	create_color(double red, double green, double blue);
int		ft_convert_prime_color_to_int(double prime_color);
long	ft_convert_color_to_longint(t_color rgb);

/* vector.c ------------------------------------------------------------------*/
t_tuple	create_tuple(double x, double y, double z, double w);

/* vector_operations.c -------------------------------------------------------*/
t_tuple	ft_add_tuples(t_tuple a, t_tuple b);
t_tuple	ft_sub_tuples(t_tuple a, t_tuple b);
t_tuple	ft_neg_tuple(t_tuple a);
t_tuple	ft_scale_tuple(t_tuple a, double scale);
double	ft_tuple_len(t_tuple a);

/* vector_operations_2.c -----------------------------------------------------*/
t_tuple	ft_normalize_tuple(t_tuple a);
double	ft_tuple_scalarproduct(t_tuple a, t_tuple b);
t_tuple	ft_multiply_tuples(t_tuple a, t_tuple b);
t_tuple	ft_multiply_tuple_by_matrix(t_tuple tuple, t_matrix4 m);
t_tuple	ft_multiply_matrix_by_tuple(t_matrix4 m, t_tuple tuple);
t_tuple	ft_multiply_tuple_by_double(t_tuple tuple, double c);
