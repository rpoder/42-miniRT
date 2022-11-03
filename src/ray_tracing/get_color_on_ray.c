/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_on_ray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margot <margot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:05:31 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/03 16:37:20 by margot           ###   ########.fr       */
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

/* ray_computation_tool :
- the point of the first intersection in world space
- the interesected object
- the eyevector = from point to camera 
- the normal vector */
static t_pcomp_tool get_ray_computation_tool(t_w_intersections w_intersections, t_ray ray)
{
	t_pcomp_tool	tool;
	t_hit			hit;

	hit = find_w_hit(w_intersections);
	tool.i = compute_new_point_on_ray(ray, hit.i);
	tool.object = hit.object;
	tool.eyev = ft_neg_tuple(ray.direction);
	tool.normalv = sphere_normal_at(tool.object, tool.i); //envoyer objet a normal et checker le type
	if (ft_tuple_scalarproduct(tool.normalv, tool.eyev) < 0)
	{
		tool.normalv = ft_neg_tuple(tool.normalv);
		tool.inside = true;
	}
	else
		tool.inside = false;
	return (tool);
}

static t_w_intersections	compute_world_intersections(t_world world, t_ray ray) //static ?
{
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
			w_intersections.i[count] = get_sphere_intersections(((t_object *)tmp->content), ray);
			w_intersections.i[count].object = tmp->content;	
			if (w_intersections.i[count].nb_of_intersections != 0)
				w_intersections.nb_of_intersected_obj++;
			tmp = tmp->next;
			count++;
		}
	}
	return (w_intersections);
}

t_color	get_color_on_ray(t_world world, t_ray ray)
{
	t_w_intersections		w_intersections;
	t_pcomp_tool			pcomp_tool;
	t_color					final_color;

	w_intersections = compute_world_intersections(world, ray);
	if (w_intersections.nb_of_intersected_obj == 0)
		return (create_color(0, 0, 0));
	else
	{
		pcomp_tool = get_ray_computation_tool(w_intersections, ray);
		//print tool//
		ft_print_tuple("i", pcomp_tool.i);
		ft_print_tuple("eyev", pcomp_tool.eyev);
		ft_print_tuple("normalv", pcomp_tool.normalv);
		printf("inside %d\n", pcomp_tool.inside);
		//////////////
		final_color = get_lighted_color(world, pcomp_tool);
	}
	return (final_color);
}
