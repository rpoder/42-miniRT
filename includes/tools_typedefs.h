/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_typedefs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:11:29 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/25 16:55:38 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_parsing_values_tool
{
	t_tuple	origin;
	t_tuple	orientation_vector;
	double	ratio;
	double	radius;
	double	height;
	double	fov;
	t_color	color;
}	t_parsing_values_tool;

typedef struct s_parsing_tool
{
	int i;
	int ret;
}	t_parsing_tool;

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
	t_tuple		over_i;
	t_tuple		eyev;
	t_tuple		normalv;
	bool		inside;
}	t_pcomp_tool;

typedef struct s_cube_faces_intersections_tool
{
	double	t_min;
	double	t_max;
}	t_cube_faces_intersections;
