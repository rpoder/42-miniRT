/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:50:05 by ronanpoder        #+#    #+#             */
/*   Updated: 2022/11/10 11:49:02 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* pattern.c----------------------------------------------------------------- */
t_pattern	create_checker_pattern(t_color a, t_color b);
t_color		checker_at(t_pattern pattern, t_tuple point);
t_color		checker_at_object(t_pattern pattern, t_object object, t_tuple point);
