/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ronanpoder <ronanpoder@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:05:31 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/02 12:15:02 by ronanpoder       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_w_intersections	compute_world_intersections(t_world world, t_ray ray)
{
	t_w_intersections	intersections;
	t_list				*tmp;
	int					count;

	if (world.objects)
		tmp = world.objects;
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

t_color	color_at(t_world world, t_ray ray)
{
	t_w_intersections		w_intersections;
	t_pcomp_tool			pcomp_tool;
	t_color					final_color;

	w_intersections = compute_world_intersections(world, ray);
	printf("world intersections nb = %d\n", w_intersections.nb_of_intersected_obj);
	if (w_intersections.nb_of_intersected_obj == 0)
		return (ft_create_color(0, 0, 0));
	return (ft_create_color(1, 1, 0));
	// pcomp_tool = precompute_ray(w_intersections, ray);
	// final_color = get_lighted_color(world, pcomp_tool);
	return (final_color);
}
