/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_intersections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:05:13 by mpourrey          #+#    #+#             */
/*   Updated: 2022/11/30 16:08:14 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_hit	find_first_object_hit(t_w_intersections w_intersections)
{
	int		j;
	t_hit	hit;

	j = 0;
	hit.i = DBL_MAX;
	while (j < w_intersections.nb_of_intersected_obj)
	{	
		if (w_intersections.i[j].nb_of_intersections > 0)
		{
			if (w_intersections.i[j].i1 < hit.i
				&& w_intersections.i[j].i1 > 0.0 + EPSILON)
			{
				hit.object = w_intersections.i[j].object;
				hit.i = w_intersections.i[j].i1;
			}
			if (w_intersections.i[j].i2 < hit.i
				&& w_intersections.i[j].i2 > 0.0 + EPSILON)
			{
				hit.object = w_intersections.i[j].object;
				hit.i = w_intersections.i[j].i2;
			}
		}
		j++;
	}
	return (hit);
}

t_hit	find_w_hit(t_w_intersections w_intersections)
{
	t_hit	hit;

	hit = find_first_object_hit(w_intersections);
	if (hit.i < DBL_MAX)
		hit.does_hit = true;
	else
	{
		hit.i = 0;
		hit.does_hit = false;
		hit.object = NULL;
	}
	return (hit);
}

t_w_intersections	get_world_intersections(t_world world, t_ray ray)
{
	t_intersections		tmp_intersections;
	t_w_intersections	w_intersections;
	t_list				*tmp;
	int					count;

	w_intersections.nb_of_intersected_obj = 0;
	count = 0;
	if (world.objects)
	{
		tmp = world.objects;
		while (tmp)
		{
			tmp_intersections = get_object_intersections(((t_object *)
						tmp->content), ray);
			if (tmp_intersections.nb_of_intersections > 0)
			{
				w_intersections.i[count] = tmp_intersections;
				w_intersections.i[count].object = ((t_object *)tmp->content);
				w_intersections.nb_of_intersected_obj++;
				count++;
			}
			tmp = tmp->next;
		}
	}
	return (w_intersections);
}
