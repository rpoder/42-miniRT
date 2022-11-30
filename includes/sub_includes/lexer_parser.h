/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:21:23 by mpourrey          #+#    #+#             */
/*   Updated: 2022/11/30 17:26:02 by mpourrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_PARSER_H
# define LEXER_PARSER_H

/* lexer.c------------------------------------------------------------------- */
void			lexer_parser(t_data *data, char *file);

/* parse_camera-------------------------------------------------------------- */
int				parse_camera(t_data *data, char *line, t_parsing_tool *tool);

/* parse_cone.c-------------------------------------------------------------- */

/* parse_lights-------------------------------------------------------------- */
int				parse_light(t_data *data, char *line, t_parsing_tool *tool);
int				parse_ambient_light(t_data *data, char *line,
					t_parsing_tool *tool);

/* parse_objects------------------------------------------------------------- */
int				parse_sphere(t_data *data, char *line, t_parsing_tool *tool);
int				parse_plane(t_data *data, char *line, t_parsing_tool *tool);
int				parse_triangle(t_data *data, char *line, t_parsing_tool *tool);
int				parse_cube(t_data *data, char *line, t_parsing_tool *tool);
int				parse_cone(t_data *data, char *line, t_parsing_tool *tool);

/* parse_objects_2----------------------------------------------------------- */
int				parse_cylinder(t_data *data, char *line, t_parsing_tool *tool);

/* parse_scene.c------------------------------------------------------------ */
int				parse_scene(t_data *data, t_list *lst);

/* parsing_objects_checker--------------------------------------------------- */
int				check_scene_is_complete(t_list *lst);

/* parsing_tool.c------------------------------------------------------------ */
t_parsing_tool	*init_parsing_tool(void);
t_parsing_tool	*set_parsing_tool(t_parsing_tool *tool);

/* parsing_values_checker---------------------------------------------------- */
int				nb_values_checker(char *line, int nb, t_parsing_tool *tool);
int				ratio_checker(double ratio, char *line, t_parsing_tool *tool);
int				color_checker(t_color color, char *line, t_parsing_tool *tool);
int				orientation_vector_checker(t_tuple or_v, char *line,
					t_parsing_tool *tool);
int				fov_checker(double fov, char *line, t_parsing_tool *tool);

/* parsing_values_checker_2-------------------------------------------------- */
int				str_value_checker(char *str_value, char *line,
					t_parsing_tool *tool);
void			print_value_error(char *value, char *line,
					t_parsing_tool *tool);

/* value_getters------------------------------------------------------------- */
t_tuple			get_coordinates(char *line, t_parsing_tool *tool);
t_tuple			get_orientation_vector(char *line, t_parsing_tool *tool);
double			get_one_parsing_value(char *line, t_parsing_tool *tool);
t_color			get_color(char *line, t_parsing_tool *tool);

/* value_getters_utils------------------------------------------------------- */
char			*get_parsing_value(int i, char *line);
void			go_to_next_value(char *line, t_parsing_tool *tool);

#endif