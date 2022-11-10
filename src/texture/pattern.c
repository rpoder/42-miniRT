/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:45:25 by ronanpoder        #+#    #+#             */
/*   Updated: 2022/11/10 11:51:05 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_pattern	create_checker_pattern(t_color a, t_color b)
{
	t_pattern	pattern;

	pattern.a = a;
	pattern.b = b;
	pattern.transform_m = get_identity_matrix();
	return (pattern);
}

t_color	checker_at(t_pattern pattern, t_tuple point)
{
	int	floored_x;
	int	floored_y;
	int	floored_z;

	floored_x = (int)floor(point.x);
	floored_y = (int)floor(point.y);
	floored_z = (int)floor(point.z);
	if ((floored_x + floored_y + floored_z) % 2 == 0)
		return (pattern.a);
	else
		return (pattern.b);
}

t_color	checker_at_object(t_pattern pattern, t_object object, t_tuple world_point)
{
	t_tuple	object_point;
	t_tuple	pattern_point;

	object_point = ft_multiply_matrix_by_tuple(ft_inverse_matrix(object.transform_m), world_point);
	pattern_point = ft_multiply_matrix_by_tuple(ft_inverse_matrix(pattern.transform_m), object_point);

	return (checker_at(pattern, pattern_point));
}
