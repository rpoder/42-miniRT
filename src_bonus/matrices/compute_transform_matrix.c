/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_transform matrix.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 19:13:36 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/30 13:46:44 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix4	compute_translation_matrix(double x, double y, double z)
{
	t_matrix4	new_m;

	new_m = get_identity_matrix();
	new_m.matrix[0][3] = x;
	new_m.matrix[1][3] = y;
	new_m.matrix[2][3] = z;
	return (new_m);
}

t_matrix4	compute_scaling_matrix(double x, double y, double z)
{
	t_matrix4	new_m;

	new_m = get_identity_matrix();
	new_m.matrix[0][0] = x;
	new_m.matrix[1][1] = y;
	new_m.matrix[2][2] = z;
	return (new_m);
}

t_matrix4	compute_shearing_matrix(t_shearing_values values)
{
	t_matrix4	new_m;

	new_m = get_identity_matrix();
	new_m.matrix[0][1] = values.xy;
	new_m.matrix[0][2] = values.xz;
	new_m.matrix[1][0] = values.yx;
	new_m.matrix[1][2] = values.yz;
	new_m.matrix[2][0] = values.zx;
	new_m.matrix[2][1] = values.zy;
	return (new_m);
}
