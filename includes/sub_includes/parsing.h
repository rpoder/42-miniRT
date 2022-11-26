/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 22:17:49 by mpourrey          #+#    #+#             */
/*   Updated: 2022/11/26 20:20:44 by rpoder           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* lexer.c------------------------------------------------------------------- */
int				lexer_parser(t_data *data, char *file);

/* parse_scene.c------------------------------------------------------------ */
int				parse_scene(t_data *data, t_list *lst);

/* parse_objects------------------------------------------------------------- */
int				parse_cube(t_data *data, char *line, t_parsing_tool *tool);

/* parsing_tool.c------------------------------------------------------------ */
t_parsing_tool	*init_parsing_tool();
void			set_parsing_tool(t_parsing_tool *tool, int i, int ret);

/* value_getters------------------------------------------------------------- */
t_tuple 		get_coordinates(char *line, t_parsing_tool *tool);
t_tuple 		get_orientation_vector(char *line, t_parsing_tool *tool);
double			get_one_parsing_value(char *line, t_parsing_tool *tool);
t_color 		get_color(char *line, t_parsing_tool *tool);
