# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ronanpoder <ronanpoder@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 17:38:32 by rpoder            #+#    #+#              #
#    Updated: 2022/11/02 11:44:14 by ronanpoder       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROGNAME			:=	minirt

LIBFT				:=	./libs/libft/libft.a
MLX					:=	./libs/minilibx-macos/libmlx

INCLUDEDIR			:=	./includes
SUBINCLUDEDIR			:=	./includes/sub_includes
SRCDIR				:=	./src

# MLXFLAGS			:=	-L/usr/lib -lXext -lX11 -lm -lz
MLXFLAGS			:= -framework OpenGL -framework AppKit

OBJDIR				:=	./obj

SRCS				:=	main.c \
						matrices/cofactor.c \
						matrices/compute_transform_matrix_2.c \
						matrices/compute_transform_matrix.c \
						matrices/determinant.c \
						matrices/matrix_operations.c \
						matrices/matrix_utils.c \
						matrices/sub_matrix.c \
						objects/sphere.c \
						ray_tracing/intersections.c \
						ray_tracing/ray.c \
						tuple/vectors.c \
						tuple/vector_operations.c \
						tuple/vector_operations_2.c \
						tuple/color_operations.c \
						tuple/colors.c \
						tools/init_tools.c \
						tools/cmp_tools.c \
						tools/print.c \
						scene/camera.c \
						scene/lights.c \
						utils/init.c \
						utils/mlx.c \

CC					:=	cc
RM					:=	rm

# CCFLAGS				:=	-Wall -Wextra -Werror

NAME				:=	$(PROGNAME)

OUTDIR				:=	$(OBJDIR)

$(OUTDIR)/%.o		:	$(SRCDIR)/%.c | $(OUTDIR)
	@mkdir -p $(dir $@)
	$(CC) -c $(CCFLAGS) -o3 -I $(INCLUDEDIR) -I $(SUBINCLUDEDIR) -I $(dir $(MLX)) -I $(dir $(LIBFT)) $< -o $@

$(NAME)				:	$(addprefix $(OUTDIR)/,$(SRCS:.c=.o)) $(LIBFT) $(MLX)
	$(CC) $(CCFLAGS) $(addprefix $(OUTDIR)/,$(SRCS:.c=.o)) -o3 -L libs/libft -lft -L libs/minilibx-macos -lmlx $(MLXFLAGS) -o $(NAME)

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
