# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tebatsai <tebatsai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/29 15:53:53 by tebatsai          #+#    #+#              #
#    Updated: 2019/10/24 23:42:57 by tebatsai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol


INCLUDES = -I$(HEADER_DIRECTORY) -I$(LIBFT_DIRECTORY) -I$(MINILIBX_DIRECTORY)

LIBFT_DIRECTORY = ./libft/
LIBFT = $(LIBFT_DIRECTORY)libft.a

MINILIBX_DIRECTORY = ./miniLibX/
MINILIBX = $(MINILIBX_DIRECTORY)libmlx.a

HEADER_DIRECTORY = ./includes/
HEADER_LIST = ft_fractol.h key.h
HEADER = $(addprefix $(HEADER_DIRECTORY), $(HEADER_LIST))

SRCS_DIRECTORY = ./srcs/
SRCS_LIST = main.c control.c changes.c press.c\
			color.c fractals.c
SRCS = $(addprefix $(SRCS_DIRECTORY), $(SRCS_LIST))

OBJECTS_DIRECTORY = build/
OBJECT_LIST = $(patsubst %.c, %.o, $(SRCS_LIST))
OBJECTS = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECT_LIST))



CC = gcc
FLAGS = -Wall -Werror -Wextra
MLX =  -lmlx -lm -lft -framework OpenGL -framework AppKit -L$(LIBFT_DIRECTORY) -L$(MINILIBX_DIRECTORY)

BIBlack=\033[1;90m   								 # Black
BIRed=\033[1;91m  # Red
BIGreen=\033[1;92m  # Green
BIYellow=\033[1;93m  # Yellow
BIBlue=\033[1;94m      # Blue
BIPurple=\033[1;95m  # Purple
BICyan=\033[1;96m       # Cyan
BIWhite=\033[1;97m  # White
BYellow= \033[1;33m  # Yellow
RESET = \033[0m

all:$(NAME)

$(NAME):$(LIBFT) $(MINILIBX) $(OBJECTS_DIRECTORY) $(OBJECTS)
	@$(CC) $(FLAGS) $(MLX) $(INCLUDES) $(OBJECTS) -o $(NAME)
	@echo "$(BIBlue)\t\t\t K å °ı° ™ $(RESET)\n"
$(OBJECTS_DIRECTORY):
	mkdir -p $(OBJECTS_DIRECTORY)

$(OBJECTS_DIRECTORY)%.o : $(SRCS_DIRECTORY)%.c $(HEADER)
	@$(CC) $(FLAGS) -g -c $(INCLUDES) $< -o $@ -g
	@echo "$(BIGreen) $(RESET)$(BIYellow)† $(RESET)\c"
	@echo "$(BIWhite)• $(RESET)$(BIPurple)◊ $(RESET)$(BIRed)∆ $(RESET)\c"

$(MINILIBX):
	make -sC $(MINILIBX_DIRECTORY)

$(LIBFT):
	make -sC $(LIBFT_DIRECTORY)

norm:
	norminette $(SRCS) $(HEADER)

clean:
	make -C $(LIBFT_DIRECTORY) clean
	make -C $(MINILIBX_DIRECTORY) clean
	/bin/rm -rf $(OBJECTS_DIRECTORY)

fclean: clean
	/bin/rm -rf $(LIBFT)
	/bin/rm -rf $(MINILIBX)
	/bin/rm -rf $(NAME)

re: fclean all
