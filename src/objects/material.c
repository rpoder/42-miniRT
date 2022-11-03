/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margot <margot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:54:41 by margot            #+#    #+#             */
/*   Updated: 2022/11/03 16:55:05 by margot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_material	get_default_material(void)
{
	t_material	mat;

	mat.color = create_color(0.8, 1, 0.6);
	mat.ambient = 0.1;
	mat.diffuse = 0.7;
	mat.specular = 0.2;
	mat.shininess = 200.0;
	return (mat);
}