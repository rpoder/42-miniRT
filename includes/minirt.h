/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:09:02 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/19 11:05:40 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define  EPSILON 0.00001

typedef struct s_tuple
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_tuple;

// utils.c
bool	ft_floatcmp(float a, float b);

// vector_operations.c
t_tuple	ft_add_tuples(t_tuple a, t_tuple b);
t_tuple	ft_sub_tuples(t_tuple a, t_tuple b);
t_tuple	ft_neg_tuple(t_tuple a);
t_tuple	ft_scale_tuple(t_tuple a, float scale);
float	ft_tuple_len(t_tuple a);
t_tuple	ft_normalize_tuple(t_tuple a);

// print.c
void	ft_print_tuple(char *tuple_name, t_tuple tuple);
