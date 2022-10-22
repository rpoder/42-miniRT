/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:18:32 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/21 18:29:03 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_counter3	init_counter3(void)
{
	t_counter3	counter;

	counter.i = 0;
	counter.j = 0;
	counter.k = 0;
	return (counter);
}

t_counter4	init_counter4(void)
{
	t_counter4	counter;

	counter.i = 0;
	counter.j = 0;
	counter.k = 0;
	counter.l = 0;
	return (counter);
}
