/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:09:02 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/07 15:19:04 by rpoder           ###   ########.fr       */
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

/* defines */
# define CANVAS_X 1000
# define CANVAS_Y 1000

# define EPSILON 0.00001

# define UNDEFINED_TYPE 100
# define SPHERE_TYPE 101

# define NO_ERR 0
# define MALLOC_ERR -1


#endif
