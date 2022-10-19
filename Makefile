# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpoder <rpoder@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 17:38:32 by rpoder            #+#    #+#              #
#    Updated: 2022/10/19 12:01:57 by rpoder           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROGNAME			:=	minirt

LIBFT				:=	./libs/libft/libft.a
MLX					:=	./libs/minilibx-linux/libmlx_Linux.a
MLX_FLAGS			:=	-L/usr/lib -lXext -lX11 -lm -lz


SRCDIR				:=	./src

OBJDIR				:=	./obj

SRCS				:=	main.c \
						print.c \
						utils.c \
						vector_operations.c \

CC					:=	cc

RM					:=	rm

CCFLAGS				:=	-Wall -Wextra -Werror

NAME				:=	$(PROGNAME)

OUTDIR				:=	$(OBJDIR)

$(OUTDIR)/%.o		:	$(SRCDIR)/%.c | $(OUTDIR)
	@mkdir -p $(dir $@)
	$(CC) -c $(CCFLAGS) -I ./includes -I ./libs/libmlx_Linux $< -o $@

$(NAME)				:	$(addprefix $(OUTDIR)/,$(SRCS:.c=.o)) $(LIBFT)
	$(CC) $(CCFLAGS) -I ./includes -I ./libs/libmlx_Linux -lm $(MLX_FLAGS) $(addprefix $(OUTDIR)/,$(SRCS:.c=.o)) $(LIBFT) -o $(NAME)

all					:	$(NAME)

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
	$(RM) -rf $(OBJDIR)

fclean				:	clean
	$(RM) -f $(PROGNAME)

re					:	fclean
					make $(NAME)

.PHONY				:	all clean fclean re
