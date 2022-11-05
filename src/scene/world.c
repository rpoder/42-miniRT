/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:14:34 by mpourrey          #+#    #+#             */
/*   Updated: 2022/11/04 16:25:02 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_matrix4 compute_orientation_matrix(t_tuple leftv, t_tuple true_upv, t_tuple forwardv)
{
	t_matrix4	orientation_m;

	orientation_m = m4_bzero();
	orientation_m.matrix[0][0] = leftv.x;
	orientation_m.matrix[1][0] = leftv.y;
	orientation_m.matrix[2][0] = leftv.z;

	

	
}

t_matrix4 compute_view_transform_m(t_tuple from, t_tuple to, t_tuple up)
{
	t_matrix4	view_transform_m;
	t_matrix4	orientation_transform_m;
	t_tuple		forwardv;
	t_tuple		leftv;
	t_tuple		true_upv;

	forwardv = ft_sub_tuples(to, from);
	leftv = ft_multiply_tuples(forwardv, ft_normalize_tuple(up));
	true_upv = ft_multiply_tuples(leftv, forwardv);
	
	orientation_transform_m = compute_orientation_matrix(leftv, true_upv, forwardv);
	
}