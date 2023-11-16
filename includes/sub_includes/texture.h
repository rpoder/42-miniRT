/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:50:05 by ronanpoder        #+#    #+#             */
/*   Updated: 2022/11/30 17:44:12 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

/* pattern.c----------------------------------------------------------------- */
t_pattern	create_checker_pattern(t_color a, t_color b);
t_color		checker_at_object(t_pattern pattern, t_object object,
				t_tuple point);

#endif