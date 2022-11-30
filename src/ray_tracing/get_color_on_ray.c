/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_on_ray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:05:31 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/30 16:09:46 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_color	normalize_color(t_color	tmp)
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

static t_color	get_color_on_object(t_world world, t_ray_pcomp_tool pcomp_tool)
{
	t_color	tmp_color;

	tmp_color = create_color(0, 0, 0);
	while (world.point_lights)
	{
		tmp_color = ft_add_colors(tmp_color, get_lighted_color(world,
					(t_point_light *)world.point_lights->content,
					pcomp_tool));
		world.point_lights = world.point_lights->next;
	}
	return (tmp_color);
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

t_color	get_color_on_ray(t_world world, t_ray ray)
{
	t_w_intersections		w_intersections;
	t_ray_pcomp_tool		pcomp_tool;
	t_color					final_color;

	w_intersections = get_world_intersections(world, ray);
	if (w_intersections.nb_of_intersected_obj == 0)
		return (create_color(0, 0, 0));
	else
	{
		pcomp_tool = get_ray_computation_tool(w_intersections, ray);
		if (pcomp_tool.object)
			final_color = get_color_on_object(world, pcomp_tool);
		else
			return (create_color(0, 0, 0));
	}
	return (normalize_color(final_color));
}
