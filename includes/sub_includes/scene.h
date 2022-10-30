/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:29:26 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/30 15:33:58 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/* lights.c------------------------------------------------------------------ */
t_point_light	ft_create_point_light(t_color intensity, t_tuple position);
static			t_tuple	ft_reflect_in(t_tuple in, t_tuple normal);
t_color			get_lighted_color(t_material mat, t_point_light light, t_tuple point, t_tuple eyev, t_tuple normalv);
