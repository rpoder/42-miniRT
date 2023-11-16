/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:08:41 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/30 16:50:08 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	ft_doublecmp(double a, double b)
{
	if (fabs(a - b) < EPSILON)
		return (true);
	return (false);
}

bool	ft_tuplescmp(t_tuple a, t_tuple b)
{
	if (a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w)
		return (true);
	return (false);
}
