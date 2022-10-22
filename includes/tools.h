/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:11:29 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/22 16:18:53 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

typedef struct s_counter3
{
	int	i;
	int	j;
	int	k;
}	t_counter3;

typedef struct s_counter4
{
	int	i;
	int	j;
	int	k;
	int	l;
}	t_counter4;

typedef struct s_shearing_values
{
	float	xy;
	float	xz;
	float	yx;
	float	yz;
	float	zx;
	float	zy;
}	t_shearing_values;
