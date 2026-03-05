# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gujarry <gujarry@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/26 21:42:03 by gujarry           #+#    #+#              #
#    Updated: 2026/03/04 18:38:42 by gujarry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

MLX_DIR		= minilibx-linux
MLX_LIB		= $(MLX_DIR)/libmlx.a
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

INCLUDES	= -I. -Ilibft -Iprintf -Iget_next_line -Imap_checker -Irender -Iinput -Ienemy -I$(MLX_DIR)

SRCS		= solong.c game.c \
			  map_checker/map_checker.c map_checker/map_load.c map_checker/map_validate_bis.c\
			  map_checker/map_validate.c map_checker/map_free.c map_checker/map_path.c \
			  render/load_sprite.c render/draw_map.c render/destroy_sprite.c \
			  input/handle_key.c \
			  enemy/ghost.c enemy/ghost_parse.c\
			  get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
			  libft/ft_strlen.c libft/ft_strdup.c libft/ft_putstr_fd.c libft/ft_bzero.c \
			  printf/ft_printf.c printf/ft_.c printf/ft_sec.c

OBJS		= $(SRCS:.c=.o)

all: $(MLX_LIB) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re