/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 13:37:48 by rpoder            #+#    #+#             */
/*   Updated: 2022/10/19 10:37:41 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(void)
{
	t_tuple	a;
	t_tuple	new;

	a.x = 1.0;
	a.y = -2.0;
	a.z = 3.0;
	a.w = -4.0;
	new = ft_normalize_tuple(a);
	ft_print_tuple("A", new);
	printf("norme de A = %f\n", ft_tuple_len(new));
}
