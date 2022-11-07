/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_typedefs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:11:29 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/07 14:49:40 by rpoder           ###   ########.fr       */
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

typedef struct s_offset
{
	double	x;
	double	y;
}	t_offset;

typedef struct s_double3
{
	double	a;
	double	b;
	double	c;
}	t_double3;

typedef struct s_ray_precompute_tool
{
	t_object	*object;
	t_tuple		i;
	t_tuple		eyev;
	t_tuple		normalv;
	bool		inside;
}	t_pcomp_tool;
