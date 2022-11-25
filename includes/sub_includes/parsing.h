/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 22:17:49 by mpourrey          #+#    #+#             */
/*   Updated: 2022/11/25 16:46:42 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* lexer.c------------------------------------------------------------------- */
int				lexer_parser(t_data *data, char *file);

/* create_scene.c------------------------------------------------------------ */
int				create_scene(t_data *data, t_list *lst, t_parsing_tool *tool);

/* parse_objects------------------------------------------------------------- */
int				parse_sphere(t_data *data, char *line, t_parsing_tool *tool);
int				parse_cylinder(t_data *data, char *line, t_parsing_tool *tool);
int				parse_plane(t_data *data, char *line, t_parsing_tool *tool);

/* value_getters------------------------------------------------------------- */
t_tuple 		get_coordinates(char *line, t_parsing_tool *tool);
t_tuple 		get_orientation_vector(char *line, t_parsing_tool *tool);
double			get_one_parsing_value(char *line, t_parsing_tool *tool);
t_color 		get_color(char *line, t_parsing_tool *tool);

/* parsing_tool.c------------------------------------------------------------ */
t_parsing_tool			*init_parsing_tool();
void					set_parsing_tool(t_parsing_tool *tool, int i, int ret);
t_parsing_values_tool	set_parsing_values_tool(t_parsing_values_tool values);

