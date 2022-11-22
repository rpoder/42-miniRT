/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margot <margot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:36:45 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/22 21:31:17 by margot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* cmp_tools.c--------------------------------------------------------------- */
bool		ft_doublecmp(double a, double b);
bool		ft_tuplescmp(t_tuple a, t_tuple b);

/* init_tools.c-------------------------------------------------------------- */
t_counter3	init_counter3(void);
t_counter4	init_counter4(void);


/* prints.c ------------------------------------------------------------------*/
void	ft_print_tuple(char *tuple_name, t_tuple tuple);
void	ft_print_color(char *color_name, t_color color);
void	ft_print_matrix4(t_matrix4 m4);
void	ft_print_matrix3(t_matrix3 m3);
void	ft_print_matrix2(t_matrix2 m2);
void	ft_print_ray(t_ray ray);
void	print_intersection(t_intersections intersections);
void	print_bits_of_long(long num);
