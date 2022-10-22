/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:13:36 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/22 19:07:53 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix4	ft_get_translate_matrix(float x, float y, float z)
{
	t_matrix4	new_m;

	new_m = ft_get_identity_matrix();
	new_m.matrix[0][3] = x;
	new_m.matrix[1][3] = y;
	new_m.matrix[2][3] = z;
	return (new_m);
}

t_matrix4	ft_get_scale_matrix(float x, float y, float z)
{
	t_matrix4	new_m;

	new_m = ft_get_identity_matrix();
	new_m.matrix[0][0] = x;
	new_m.matrix[1][1] = y;
	new_m.matrix[2][2] = z;
	return (new_m);
}

t_matrix4	ft_get_rotate_x_matrix(float radian)
{
	t_matrix4	new_m;

	new_m = ft_get_identity_matrix();
	new_m.matrix[1][1] = cosf(radian);
	new_m.matrix[1][2] = -sinf(radian);
	new_m.matrix[2][1] = sinf(radian);
	new_m.matrix[2][2] = cosf(radian);
	return (new_m);
}

t_matrix4	ft_get_rotate_y_matrix(float radian)
{
	t_matrix4	new_m;

	new_m = ft_get_identity_matrix();
	new_m.matrix[0][0] = cosf(radian);
	new_m.matrix[0][2] = sinf(radian);
	new_m.matrix[2][0] = -sinf(radian);
	new_m.matrix[2][2] = cosf(radian);
	ft_print_matrix4(new_m);
	return (new_m);
}

t_matrix4	ft_get_rotate_z_matrix(float radian)
{
	t_matrix4	new_m;

	new_m = ft_get_identity_matrix();
	new_m.matrix[0][0] = cosf(radian);
	new_m.matrix[0][1] = -sinf(radian);
	new_m.matrix[1][0] = sinf(radian);
	new_m.matrix[1][1] = cosf(radian);
	return (new_m);
}

t_matrix4	ft_get_shear_matrix(t_shearing_values values)
{
	t_matrix4	new_m;

	new_m = ft_get_identity_matrix();
	new_m.matrix[0][1] = values.xy;
	new_m.matrix[0][2] = values.xz;
	new_m.matrix[1][0] = values.yx;
	new_m.matrix[1][2] = values.yz;
	new_m.matrix[2][0] = values.zx;
	new_m.matrix[2][1] = values.zy;
	return (new_m);
}
