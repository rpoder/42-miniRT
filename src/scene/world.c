/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:14:34 by mpourrey          #+#    #+#             */
/*   Updated: 2022/11/28 00:12:15 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_matrix4 compute_orientation_matrix(t_tuple leftv, t_tuple true_upv, t_tuple forwardv, t_tuple from)
{
	t_matrix4	orientation_m;
	t_matrix4	translation_m;

	orientation_m = get_identity_matrix();
	orientation_m.matrix[0][0] = leftv.x;
	orientation_m.matrix[0][1] = leftv.y;
	orientation_m.matrix[0][2] = leftv.z;
	orientation_m.matrix[1][0] = true_upv.x;
	orientation_m.matrix[1][1] = true_upv.y;
	orientation_m.matrix[1][2] = true_upv.z;
	orientation_m.matrix[2][0] = -forwardv.x;
	orientation_m.matrix[2][1] = -forwardv.y;
	orientation_m.matrix[2][2] = -forwardv.z;
	translation_m = compute_translation_matrix(-from.x, -from.y, -from.z);
	return(multiply_matrices(orientation_m, translation_m));
}

t_matrix4 compute_view_transform_m(t_tuple from, t_tuple to, t_tuple up)
{
	t_matrix4	view_transform_m;
	t_tuple		forwardv;
	t_tuple		leftv;
	t_tuple		true_upv;

	forwardv = normalize_tuple(sub_tuples(to, from));
	leftv = cross_product(forwardv, normalize_tuple(up));
	true_upv = cross_product(leftv, forwardv);
	view_transform_m = compute_orientation_matrix(leftv, true_upv, forwardv, from);
	return(view_transform_m);
}
