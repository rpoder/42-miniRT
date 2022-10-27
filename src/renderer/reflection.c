/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:37:19 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/27 15:44:02 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	ft_reflect(t_tuple in, t_tuple normal)
{
	return (ft_sub_tuples(in, ft_scale_tuple(normal, 2.0 * ft_tuple_scalarproduct(in, normal))));
}
