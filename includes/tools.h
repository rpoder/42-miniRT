/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:11:29 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/23 15:32:17 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

typedef struct s_offset
{
	int	x;
	int	y;
}	t_offset;

typedef struct s_float3
{
	float	a;
	float	b;
	float	c;
}	t_float3;
