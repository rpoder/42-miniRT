/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedefs.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 12:28:40 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/27 13:13:45 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"
# include <stdbool.h>

typedef struct	s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_mlx_data
{
	void		*mlx;
	void		*win;
	t_image		image;
}	t_mlx_data;

typedef struct	s_data {
	t_mlx_data	*mlx_data;
	t_list		*objects;
}	t_data;

typedef struct	s_matrix4{
	double	matrix[4][4];
}	t_matrix4;

typedef struct	s_matrix3{
	double	matrix[3][3];
}	t_matrix3;

typedef struct	s_matrix2{
	double	matrix[2][2];
}	t_matrix2;

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

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
}	t_ray;

typedef struct s_object
{
	int			id;
	int			object_type;
	t_matrix4	transform_m;
	t_tuple		origin;
	double		radius;
	t_color		color;
}	t_object;

typedef struct s_intersections
{
	int			nb_of_intersections;
	int			object_type;
	double		i1;
	double		i2;
}	t_intersections;

typedef struct s_hit
{
	bool	does_hit;
	double	i;
}	t_hit;
