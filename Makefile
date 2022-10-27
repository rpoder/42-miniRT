# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 17:38:32 by rpoder            #+#    #+#              #
#    Updated: 2022/10/27 15:43:39 by rpoder           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROGNAME			:=	minirt

LIBFT				:=	./libs/libft/libft.a
MLX					:=	./libs/minilibx-linux/libmlx_Linux.a

INCLUDEDIR			:=	./includes
SRCDIR				:=	./src

MLXFLAGS			:=	-L/usr/lib -lXext -lX11 -lm -lz

OBJDIR				:=	./obj


SRCS				:=	main.c \
						tuple/vector_operations.c \
						tuple/color_operations.c \
						matrix/matrix_operations.c \
						matrix/inverse_matrix_utils.c \
						matrix/inverse_matrix_utils_2.c \
						matrix/matrix_utils.c \
						matrix/sub_matrix_getters.c \
						matrix/transform_matrix.c \
						tools/init_tools.c \
						tools/print.c \
						tools/utils.c \
						renderer/canvas.c \
						renderer/reflection.c \
						ray/ray_utils.c \
						ray/hits_utils.c \
						objects/sphere_utils.c


CC					:=	cc
RM					:=	rm

# CCFLAGS				:=	-Wall -Wextra -Werror

NAME				:=	$(PROGNAME)

OUTDIR				:=	$(OBJDIR)

$(OUTDIR)/%.o		:	$(SRCDIR)/%.c | $(OUTDIR)
	@mkdir -p $(dir $@)
	$(CC) -c $(CCFLAGS) -I $(INCLUDEDIR) $(addprefix -I ,$(dir $(MLX))) $(addprefix -I ,$(dir $(LIBFT))) $< -o $@

$(NAME)				:	$(addprefix $(OUTDIR)/,$(SRCS:.c=.o)) $(LIBFT) $(MLX)
	$(CC) $(CCFLAGS) $(addprefix $(OUTDIR)/,$(SRCS:.c=.o)) $(MLXFLAGS) $(LIBFT) $(MLX) -o $(NAME)

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
