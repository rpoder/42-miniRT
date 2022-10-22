/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:13:36 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/22 14:09:47 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix4	ft_translate_matrix(float x, float y, float z)
{
	t_matrix4	new_m;

	new_m = ft_get_identity_matrix();
	new_m.matrix[0][3] = x;
	new_m.matrix[1][3] = y;
	new_m.matrix[2][3] = z;
	return (new_m);
}

t_matrix4	ft_scale_matrix(float x, float y, float z)
{
	t_matrix4	new_m;

	new_m = ft_get_identity_matrix();
	new_m.matrix[0][0] = x;
	new_m.matrix[1][1] = y;
	new_m.matrix[2][2] = z;
	return (new_m);
}

t_matrix4	ft_rotatex_matrix(float radian)
{
	t_matrix4	new_m;

	new_m = ft_get_identity_matrix();
	new_m.matrix[1][1] = cosf(radian);
	new_m.matrix[1][2] = -sinf(radian);
	new_m.matrix[2][1] = sinf(radian);
	new_m.matrix[2][2] = cos(radian);
	return (new_m);
}
