/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:13:36 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/27 13:14:36 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix4	ft_calculate_translation_matrix(double x, double y, double z)
{
	t_matrix4	new_m;

	new_m = ft_get_identity_matrix();
	new_m.matrix[0][3] = x;
	new_m.matrix[1][3] = y;
	new_m.matrix[2][3] = z;
	return (new_m);
}

t_matrix4	ft_calculate_scaling_matrix(double x, double y, double z)
{
	t_matrix4	new_m;

	new_m = ft_get_identity_matrix();
	new_m.matrix[0][0] = x;
	new_m.matrix[1][1] = y;
	new_m.matrix[2][2] = z;
	return (new_m);
}

t_matrix4	ft_calculate_rotation_x_matrix(double radian)
{
	t_matrix4	new_m;

	new_m = ft_get_identity_matrix();
	new_m.matrix[1][1] = cos(radian);
	new_m.matrix[1][2] = -sin(radian);
	new_m.matrix[2][1] = sin(radian);
	new_m.matrix[2][2] = cos(radian);
	return (new_m);
}

t_matrix4	ft_calculate_rotation_y_matrix(double radian)
{
	t_matrix4	new_m;

	new_m = ft_get_identity_matrix();
	new_m.matrix[0][0] = cos(radian);
	new_m.matrix[0][2] = sin(radian);
	new_m.matrix[2][0] = -sin(radian);
	new_m.matrix[2][2] = cos(radian);
	ft_print_matrix4(new_m);
	return (new_m);
}

t_matrix4	ft_calculate_rotation_z_matrix(double radian)
{
	t_matrix4	new_m;

	new_m = ft_get_identity_matrix();
	new_m.matrix[0][0] = cos(radian);
	new_m.matrix[0][1] = -sin(radian);
	new_m.matrix[1][0] = sin(radian);
	new_m.matrix[1][1] = cos(radian);
	return (new_m);
}

t_matrix4	ft_calculate_shearing_matrix(t_shearing_values values)
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
