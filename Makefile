# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpourrey <mpourrey@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 17:38:32 by rpoder            #+#    #+#              #
#    Updated: 2022/11/19 18:24:08 by mpourrey         ###   ########.fr        #
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
						objects/object.c \
						objects/object_intersections.c \
						objects/material.c \
						objects/sphere.c \
						objects/plane.c \
						objects/cube.c \
						objects/cylinder.c \
						objects/cone.c \
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
						scene/lights.c \
						scene/world.c \
						scene/camera.c \
						utils/init.c \
						utils/mlx.c \
						texture/pattern.c \

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

re					:	fclean $(NAME)


.PHONY				:	all clean fclean re
