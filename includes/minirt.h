/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:09:02 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/27 18:37:13 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
#define MINIRT_H

/* libs */
# include "mlx.h"
# include <stdio.h>
# include <math.h>
# include <sys/time.h>
# include <stdbool.h>
# include <float.h>
#include <fcntl.h>

# include "libft.h"
# include "typedefs.h"
# include "tools_typedefs.h"

/* includes/sub_includes */
# include "matrices.h"
# include "objects.h"
# include "ray_tracing.h"
# include "utils.h"
# include "scene.h"
# include "tools.h"
# include "tuples.h"
# include "texture.h"
# include "parsing.h"

/* defines */
# define CANVAS_X 				640
# define CANVAS_Y				320

# define EPSILON				0.00001
# define ACNE_PRECISION			0.0001

# define UNDEFINED_TYPE			100

# define NO_ERR					0
# define MALLOC_ERR 			1
# define PARSING_ERR			2

# define SPHERE_TYPE			10
# define CUBE_TYPE				11
# define PLANE_TYPE				12
# define CYLINDER_TYPE			13
# define CONE_TYPE			14

/* TEXTURE TYPES */
# define SOLID_TEXTURE_TYPE		200
# define PATTERN_TEXTURE_TYPE	201

#endif
