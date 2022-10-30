/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_transform_matrix_2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 13:47:10 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/30 13:47:26 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix4	compute_rotation_x_matrix(double radian)
{
	t_matrix4	new_m;

	new_m = get_identity_matrix();
	new_m.matrix[1][1] = cos(radian);
	new_m.matrix[1][2] = -sin(radian);
	new_m.matrix[2][1] = sin(radian);
	new_m.matrix[2][2] = cos(radian);
	return (new_m);
}

t_matrix4	compute_rotation_y_matrix(double radian)
{
	t_matrix4	new_m;

	new_m = get_identity_matrix();
	new_m.matrix[0][0] = cos(radian);
	new_m.matrix[0][2] = sin(radian);
	new_m.matrix[2][0] = -sin(radian);
	new_m.matrix[2][2] = cos(radian);
	ft_print_matrix4(new_m);
	return (new_m);
}

t_matrix4	compute_rotation_z_matrix(double radian)
{
	t_matrix4	new_m;

	new_m = get_identity_matrix();
	new_m.matrix[0][0] = cos(radian);
	new_m.matrix[0][1] = -sin(radian);
	new_m.matrix[1][0] = sin(radian);
	new_m.matrix[1][1] = cos(radian);
	return (new_m);
}
