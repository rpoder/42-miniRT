/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_on_ray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:05:31 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/30 15:32:40 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_hit	find_w_hit(t_w_intersections w_intersections)
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

/* ray_computation_tool :
- the point of the first intersection in world space
- the interesected object
- the eyevector = from point to camera
- the normal vector */
static t_ray_pcomp_tool	get_ray_computation_tool(
		t_w_intersections w_intersections, t_ray ray)
{
	t_ray_pcomp_tool	pcomp;
	t_hit				hit;

	hit = find_w_hit(w_intersections);
	if (hit.does_hit == false)
	{
		pcomp.object = NULL;
		return (pcomp);
	}
	pcomp.i = compute_new_point_on_ray(ray, hit.i);
	pcomp.over_i = pcomp.i;
	pcomp.object = hit.object;
	pcomp.eyev = ft_neg_tuple(ray.direction);
	pcomp.normalv = get_object_normal_at(pcomp.object, pcomp.i);
	if (dot_product(pcomp.normalv, pcomp.eyev) < 0)
	{
		pcomp.normalv = ft_neg_tuple(pcomp.normalv);
		pcomp.inside = true;
	}
	else
		pcomp.inside = false;
	return (pcomp);
}

t_w_intersections	compute_world_intersections(t_world world, t_ray ray)
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

t_color	normalize_color(t_color	tmp)
{
	t_color	final_color;
	double	max;
	double	coef;

	if (tmp.red >= tmp.blue && tmp.red >= tmp.green)
		max = tmp.red;
	if (tmp.blue >= tmp.red && tmp.red >= tmp.green)
		max = tmp.blue;
	if (tmp.green >= tmp.blue && tmp.red >= tmp.red)
		max = tmp.green;
	if (max > 1)
	{
		coef = 1 / max;
		final_color.red = tmp.red * coef;
		final_color.green = tmp.green * coef;
		final_color.blue = tmp.blue * coef;
		return (final_color);
	}
	return (tmp);
}

t_color	get_color_on_ray(t_world world, t_ray ray)
{
	t_w_intersections		w_intersections;
	t_ray_pcomp_tool		pcomp_tool;
	t_color					tmp_color;
	t_color					final_color;

	w_intersections = compute_world_intersections(world, ray);
	if (w_intersections.nb_of_intersected_obj == 0)
		return (create_color(0, 0, 0));
	else
	{
		pcomp_tool = get_ray_computation_tool(w_intersections, ray);
		if (pcomp_tool.object)
		{
			tmp_color = create_color(0, 0, 0);
			while (world.point_lights)
			{
				tmp_color = ft_add_colors(tmp_color, get_lighted_color(world,
							(t_point_light *)world.point_lights->content,
							pcomp_tool));
				world.point_lights = world.point_lights->next;
			}
		}
		else
			return (create_color(0, 0, 0));
	}
	return (normalize_color(tmp_color));
}
