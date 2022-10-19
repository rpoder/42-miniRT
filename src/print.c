/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:46:08 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/19 10:37:41 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_print_tuple(char *tuple_name, t_tuple tuple)
{
	printf("%s(%f, %f, %f, %f)\n", tuple_name, tuple.x, tuple.y, tuple.z, tuple.w);
}
