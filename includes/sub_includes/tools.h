/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 15:36:45 by rpoder            #+#    #+#             */
/*   Updated: 2022/12/01 01:26:06 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

/* cmp_tools.c--------------------------------------------------------------- */
bool		ft_doublecmp(double a, double b);
bool		ft_tuplescmp(t_tuple a, t_tuple b);

/* init_tools.c-------------------------------------------------------------- */
t_counter3	init_counter3(void);
t_counter4	init_counter4(void);

#endif
