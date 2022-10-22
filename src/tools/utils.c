/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:08:41 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/22 17:31:01 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	ft_floatcmp(float a, float b)
{
	if (fabsf(a - b) < EPSILON)
		return (true);
	return (false);
}

bool	ft_tuplescmp(t_tuple a, t_tuple b)
{
	if (a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w)
		return (true);
	return (false);
}

