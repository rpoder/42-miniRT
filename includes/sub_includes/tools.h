/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:36:45 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/30 17:45:37 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

/* cmp_tools.c--------------------------------------------------------------- */
bool		ft_doublecmp(double a, double b);
bool		ft_tuplescmp(t_tuple a, t_tuple b);

/* init_tools.c-------------------------------------------------------------- */
t_counter3	init_counter3(void);
t_counter4	init_counter4(void);

//ASUPP
/* prints.c ------------------------------------------------------------------*/
void	print_tuple(char *tuple_name, t_tuple tuple);
void	printcolor(char *color_name, t_color color);
void	printmatrix4(t_matrix4 m4);
void	printmatrix3(t_matrix3 m3);
void	printmatrix2(t_matrix2 m2);
void	printray(t_ray ray);
void	print_intersection(t_intersections intersections);
void	print_bits_of_long(long num);
void	print_world(t_data *data);

#endif