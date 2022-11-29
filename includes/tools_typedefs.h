/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_typedefs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:11:29 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/29 18:28:00 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_light_values_tool
{
	t_tuple	origin;
	double	ratio;
	t_color	color;
	
}	t_light_values_tool;

typedef struct s_camera_values_tool
{
	t_tuple	origin;
	t_tuple	orientation_vector;
	double	radius;
	double	fov;

}	t_camera_values_tool;

typedef struct s_triangle_values_tool
{
	t_tuple	origin;
	t_tuple	orientation_vector;
	t_color	color;
	t_tuple	p1;
	t_tuple	p2;
	t_tuple	p3;

}	t_triangle_values_tool;

typedef struct s_plane_values_tool
{
	t_tuple	origin;
	t_tuple	orientation_vector;
	t_color	color;

}	t_plane_values_tool;

typedef struct s_sphere_values_tool
{
	t_tuple	origin;
	double	radius;
	t_color	color;

}	t_sphere_values_tool;

typedef struct s_cylinder_values_tool
{
	t_tuple	origin;
	t_tuple	orientation_vector;
	double	radius;
	double	height;
	t_color	color;

}	t_cylinder_values_tool;

typedef struct s_cube_values_tool
{
	t_tuple	origin;
	double	radius;
	t_color	color;
}	t_cube_values_tool;

typedef struct s_parsing_tool
{
	int i;
	int error;
}	t_parsing_tool;

typedef struct	check_parsing_tool
{
	int		camera;
	int		ambient;
	long	lights;
	long	objects;
}	t_check_parsing_tool;

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

typedef struct s_ray_pcomp_tool
{
	t_object	*object;
	t_tuple		i;
	t_tuple		over_i;
	t_tuple		eyev;
	t_tuple		normalv;
	bool		inside;
}	t_ray_pcomp_tool;

typedef struct s_cube_faces_intersections_tool
{
	double	t_min;
	double	t_max;
}	t_cube_faces_intersections;
