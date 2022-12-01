/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margot <margot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:48:45 by rpoder            #+#    #+#             */
/*   Updated: 2022/11/03 12:14:10 by margot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	create_tuple(double x, double y, double z, double w)
{
	t_tuple	new_tuple;

	new_tuple.x = x;
	new_tuple.y = y;
	new_tuple.z = z;
	new_tuple.w = w;
	return (new_tuple);
}
