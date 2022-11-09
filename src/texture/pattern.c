/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ronanpoder <ronanpoder@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:45:25 by ronanpoder        #+#    #+#             */
/*   Updated: 2022/11/09 17:59:36 by ronanpoder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_pattern	create_stripe_pattern(t_color a, t_color b)
{
	t_pattern	pattern;

	pattern.a = a;
	pattern.b = b;
	return (pattern);
}

t_color	stripe_at(t_pattern pattern, t_tuple point)
{
	int	rounded;

	rounded = (int)floor(point.x);
	if (rounded % 2 == 0)
		return (pattern.a);
	else
		return (pattern.b);
}
