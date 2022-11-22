/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: margot <margot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 22:17:49 by mpourrey          #+#    #+#             */
/*   Updated: 2022/11/22 23:27:12 by margot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* lexer.c------------------------------------------------------------------- */
int				lexer_parser(t_data *data, char *file);

/* create_scene.c------------------------------------------------------------ */
int				create_scene(t_data *data, t_list *lst, t_parsing_tool *tool);


/* parsing_tool.c------------------------------------------------------------ */
t_parsing_tool	*init_parsing_tool();
void			set_parsing_tool(t_parsing_tool *tool, int i, int ret);

/* value_getters------------------------------------------------------------- */
t_tuple 		get_coordinates(char *line, t_parsing_tool *tool);
double			get_one_value(char *line, t_parsing_tool *tool);
t_color 		get_color(char *line, t_parsing_tool *tool);
