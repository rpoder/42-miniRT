/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:05:31 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/30 20:31:15 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_w_intersections	compute_world_intersections(t_data *data, t_ray ray)
{
	t_w_intersections	intersections;
	t_list				*tmp;
	int					count;

	if (data->objects)
		tmp = data->objects;
	intersections.nb_of_intersected_obj = 0;
	while (tmp)
	{
		intersections.i[count] = get_sphere_intersections(((t_object *)tmp->content), ray);
		intersections.i[count].object = tmp->content;
		tmp = tmp->next;
		intersections.nb_of_intersected_obj++;
		count++;
	}
	return (intersections);
}

t_intersections	init_intersections(void)
{
	t_intersections	new_intersections;

	new_intersections.nb_of_intersections = 0;
	new_intersections.object = NULL;
	new_intersections.i1 = 0;
	new_intersections.i2 = 0;
	return (new_intersections);
}

t_hit	find_hit(t_intersections intersections)
{
	t_hit	hit;

	hit.object = intersections.object;
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
