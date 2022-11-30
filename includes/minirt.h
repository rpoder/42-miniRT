/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:09:02 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/30 17:12:08 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

/* INCLUDES */
# include "mlx.h"
# include <stdio.h>
# include <math.h>
# include <sys/time.h>
# include <stdbool.h>
# include <float.h>
# include <fcntl.h>

# include "libft.h"
# include "typedefs.h"
# include "tools_typedefs.h"

/* SUB_INCLUDES */
# include "matrices.h"
# include "objects.h"
# include "ray_tracing.h"
# include "utils.h"
# include "scene.h"
# include "tools.h"
# include "tuples.h"
# include "texture.h"
# include "lexer_parser.h"

/* DEFINES */
# define CANVAS_X 				840
# define CANVAS_Y				680

# define EPSILON				0.00001
# define ACNE					0.0001

# define UNDEFINED_TYPE			100

# define NO_ERR					0
# define MALLOC_ERR 			1
# define PARSING_ERR			2
# define MLX_ERR				3

# define SPHERE_TYPE			10
# define CUBE_TYPE				11
# define PLANE_TYPE				12
# define CYLINDER_TYPE			13
# define CONE_TYPE				14
# define TRIANGLE_TYPE			15

/* TEXTURE TYPES */
# define SOLID_TEXTURE_TYPE		200
# define PATTERN_TEXTURE_TYPE	201

#endif
