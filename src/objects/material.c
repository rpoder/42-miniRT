/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:54:41 by margot            #+#    #+#             */
/*   Updated: 2022/11/10 11:43:29 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_material	get_default_material(void)
{
	t_material	mat;

	mat.color = create_color(1, 1, 1);
	mat.ambient = 0.1;
	mat.diffuse = 0.7;
	mat.specular = 0.5;
	mat.shininess = 200.0;
	mat.texture_type = SOLID_TEXTURE_TYPE;
	return (mat);
}
