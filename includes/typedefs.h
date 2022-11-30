/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 12:28:40 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/30 17:17:28 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEFS_H
# define TYPEDEFS_H

/* MATRICES------------------------------------------------------------------ */
typedef struct s_matrix4 {
	double	matrix[4][4];
}	t_matrix4;

typedef struct s_matrix3 {
	double	matrix[3][3];
}	t_matrix3;

typedef struct s_matrix2 {
	double	matrix[2][2];
}	t_matrix2;

/* UTILS--------------------------------------------------- */
typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_tuple;

typedef struct s_color
{
	double	red;
	double	green;
	double	blue;
}	t_color;

typedef struct s_pattern
{
	t_color		a;
	t_color		b;
	t_matrix4	transform_m;
}	t_pattern;

/* WORLD--------------------------------------------------------------------- */
typedef struct s_material
{
	int			texture_type;
	t_color		color;
	double		diffuse;
	double		specular;
	double		shininess;
	t_pattern	pattern;
}	t_material;

typedef struct s_triangle_caracteristics
{
	t_tuple	p1;
	t_tuple	p2;
	t_tuple	p3;
	t_tuple	e1;
	t_tuple	e2;
	t_tuple	normal;
}	t_triangle_caracteristics;

typedef struct s_object
{
	int							id;
	int							object_type;
	t_matrix4					transform_m;
	double						min;
	double						max;
	bool						is_capped;
	t_material					material;
	t_triangle_caracteristics	triangle_cars;
}	t_object;

typedef struct s_point_light
{
	t_color	intensity;
	t_tuple	position;
}	t_point_light;

typedef struct s_camera {
	int			hsize;
	int			vsize;
	double		fov;
	t_matrix4	transform_m;
	double		pixel_size;
	double		half_width;
	double		half_height;
}	t_camera;

typedef struct s_world {
	t_list		*objects;
	t_list		*point_lights;
	t_color		ambient_light;
	t_camera	*camera;
}	t_world;

/* RAY----------------------------------------------------------------------- */
typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
}	t_ray;

typedef struct s_intersections
{
	int			nb_of_intersections;
	t_object	*object;
	double		i1;
	double		i2;
}	t_intersections;

typedef struct s_w_intersections
{
	int					nb_of_intersected_obj;
	t_intersections		i[100];
}	t_w_intersections;

typedef struct s_hit
{
	bool		does_hit;
	t_object	*object;
	double		i;
}	t_hit;

/* MLX----------------------------------------------------------------------- */
typedef struct s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_mlx_data {
	void		*mlx;
	void		*win;
	t_image		image;
}	t_mlx_data;

/* DATA---------------------------------------------------------------------- */
typedef struct s_data
{
	t_mlx_data	*mlx_data;
	t_world		*world;
}	t_data;

typedef struct s_shearing_values
{
	double	xy;
	double	xz;
	double	yx;
	double	yz;
	double	zx;
	double	zy;
}	t_shearing_values;

#endif