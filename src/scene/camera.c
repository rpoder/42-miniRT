/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:53:37 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/30 20:31:44 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_hit	find_w_hit(t_w_intersections w_intersections)
{
	int		j;
	t_hit	hit;

	j = 0;
	hit.i = DBL_MAX;
	while (j < w_intersections.nb_of_intersected_obj)
	{
		if (w_intersections.i[j].nb_of_intersections > 0)
		{
			if (w_intersections.i[j].i1 < hit.i && w_intersections.i[j].i1 > 0)
			{
				hit.object = w_intersections.i[j].object;
				hit.i = w_intersections.i[j].i1;
			}
			if (w_intersections.i[j].i2 < hit.i && w_intersections.i[j].i2 > 0)
			{
				hit.object = w_intersections.i[j].object;
				hit.i = w_intersections.i[j].i2;
			}
		}
		j++;
	}
	if (hit.i < DBL_MAX)
		hit.does_hit = true;
	else
		hit.does_hit = false;
	return (hit);
}

t_ray_precompute_tool precompute_ray(t_w_intersections w_intersections, t_ray ray)
{
	t_ray_precompute_tool	tool;

	tool.hit = find_w_hit(w_intersections);
	tool.w_point = compute_new_point_on_ray(ray, tool.hit.i);
	tool.eyev = ft_neg_tuple(ray.direction);
	///////////////envoyer hit a normal_at et y checker le type de l'objet
	tool.normalv = sphere_normal_at(tool.hit.object, tool.w_point);
	if (ft_tuple_scalarproduct(tool.normalv, tool.eyev) < 0)
	{
		tool.normalv = ft_neg_tuple(tool.normalv);
		tool.inside = true;
	}
	else
		tool.inside = false;
	return (tool);
}
