/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hits_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:05:31 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/23 18:56:52 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_hit	find_hit(t_intersections intersections)
{
	t_hit	hit;

	if ((intersections.i1 < 0 && intersections.i2 < 0)
		|| intersections.nb_of_intersections == 0)
	{
		hit.does_hit = false;
		hit.i = 0;
	}
	else
	{
		hit.does_hit = true;
		if (intersections.i1 < 0)
			hit.i = intersections.i2;
		else if (intersections.i2 < 0)
			hit.i = intersections.i1;
		else if (intersections.i1 < intersections.i2)
			hit.i = intersections.i1;
		else
			hit.i = intersections.i2;
	}
	return (hit);
}
