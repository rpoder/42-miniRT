# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 17:38:32 by rpoder            #+#    #+#              #
#    Updated: 2022/11/29 15:57:44 by mpourrey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROGNAME			:=	minirt

LIBFT				:=	./libs/libft/libft.a
MLX					:=	./libs/minilibx-linux/libmlx_Linux.a

INCLUDEDIR			:=	./includes
SUBINCLUDEDIR		:=	./includes/sub_includes
SRCDIR				:=	./src

MLXFLAGS			:=	-L/usr/lib -lXext -lX11 -lm -lz

OBJDIR				:=	./obj

SRCS				:=	main.c \
						matrices/cofactor.c \
						matrices/compute_transform_matrix_2.c \
						matrices/compute_transform_matrix.c \
						matrices/determinant.c \
						matrices/matrix_operations.c \
						matrices/matrix_utils.c \
						matrices/sub_matrix.c \
						objects/abstract_object/abstract_object_intersections.c \
						objects/abstract_object/abstract_object_normal.c \
						objects/abstract_object/material.c \
						objects/cone/cone_intersections.c \
						objects/cone/cone_normal.c \
						objects/cone/create_cone.c \
						objects/cube/create_cube.c \
						objects/cylinder/create_cylinder.c \
						objects/cylinder/cylinder_intersections.c \
						objects/cylinder/cylinder_normal.c \
						objects/plane/create_plane.c \
						objects/plane/plane_normal_and_intersections.c \
						objects/sphere/create_sphere.c \
						objects/sphere/sphere_normal_and_intersections.c \
						objects/triangle/create_triangle.c \
						objects/triangle/triangle_normal_and_intersections.c \
						ray_tracing/get_color_on_ray.c \
						ray_tracing/get_lighted_color.c \
						ray_tracing/ray.c \
						tuple/vectors.c \
						tuple/vector_operations.c \
						tuple/vector_operations_2.c \
						tuple/color_operations.c \
						tuple/colors.c \
						tools/init_tools.c \
						tools/cmp_tools.c \
						tools/print.c \
						scene/point_lights.c \
						scene/world.c \
						scene/camera.c \
						utils/init.c \
						utils/mlx.c \
						utils/frees.c \
						texture/pattern.c \
						lexer_parser/parse_scene.c \
						lexer_parser/lexer_parser.c \
						lexer_parser/parse_objects.c \
						lexer_parser/parse_lights.c \
						lexer_parser/parse_camera.c \
						lexer_parser/parsing_objects_checker.c \
						lexer_parser/parsing_values_checker.c \
						lexer_parser/parsing_tool.c \
						lexer_parser/value_getters.c \


CC					:=	cc
RM					:=	rm

# CCFLAGS				:=	-Wall -Wextra -Werror

NAME				:=	$(PROGNAME)

OUTDIR				:=	$(OBJDIR)

$(OUTDIR)/%.o		:	$(SRCDIR)/%.c | $(OUTDIR)
	@mkdir -p $(dir $@)
	$(CC) -c $(CCFLAGS) -o3 -I $(INCLUDEDIR) -I $(SUBINCLUDEDIR) -I $(dir $(MLX)) -I $(dir $(LIBFT)) $< -o $@

$(NAME)				:	$(addprefix $(OUTDIR)/,$(SRCS:.c=.o)) $(LIBFT) $(MLX)
	$(CC) $(CCFLAGS) $(addprefix $(OUTDIR)/,$(SRCS:.c=.o)) -o3 -L libs/libft -lft -L libs/minilibx-linux -lmlx_Linux $(MLXFLAGS) -o $(NAME)

all					:	$(NAME)

bonus				:	$(NAME)

ifdef LIBFT
$(LIBFT)			:
	$(MAKE) -C $(dir $(LIBFT)) all
endif

ifdef MLX
$(MLX)			:
	$(MAKE) -C $(dir $(MLX)) all
endif

$(OUTDIR)			:
	mkdir $(OUTDIR)

clean				:
ifdef LIBFT
	$(MAKE) -C $(dir $(LIBFT)) fclean
endif
ifdef MLX
	$(MAKE) -C $(dir $(MLX)) clean
endif
	$(RM) -rf $(OBJDIR)

fclean				:	clean
	$(RM) -f $(PROGNAME)

re					:	fclean
	make $(NAME)


.PHONY				:	all clean fclean re
