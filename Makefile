# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgauther <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/10 14:50:46 by vgauther          #+#    #+#              #
#    Updated: 2018/01/19 15:26:31 by vgauther         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COLORS

RESET=\033[0m
DARK=\033[132m
RED=\033[31m
GREEN=\033[32m
YELLOW=\033[33m
BLUE=\033[34m
MAGENTA=\033[35m
CYAN=\033[36m
WHITE=\033[37m
BOLDBLACK=\033[1m\033[30m
BOLDRED=\033[1m\033[31m
BOLDWHITE=\033[1m\033[37m

.PHONY: all, $(NAME), clean, fclean, re

NAME = fractol

CC = gcc
CC_FLAGS = -Wall -Werror -Wextra -g -O0
FRAMWK = -framework OpenGL -framework AppKit

SRC_PATH = ./SRCS/
INC_PATH = ./INCLUDES/
OBJ_PATH = ./OBJ/
LFT_PATH = ./libft/
MLX_PATH = ./minilibx_macos/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

OBJ_NAME = $(SRC_NAME:.c=.o)

INC_NAME = fract.h

SRC_NAME = main.c error.c julia.c mandelbrot.c put_pixel_image.c \
		burning_ship.c key_hook.c

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(RESET)$(CYAN)MAKING LIBFT ...$(RESET)"
	@make -C $(LFT_PATH)
	@echo "$(RESET)$(GREEN)LIBFTDONE\n$(RESET)"
	@echo "$(RESET)$(CYAN)MAKING MLX LIB ...$(RESET)"
	@make -C $(MLX_PATH)
	@echo "$(RESET)$(GREEN)MLX DONE\n$(RESET)"
	@$(CC) -o $(NAME) $(OBJ) -lm -L $(LFT_PATH) -lft -L ./minilibx_macos\/ -lmlx -lm $(FRAMWK)
	@echo "$(RESET)$(GREEN)[✓] EXECUTABLE FRACTOL DONE$(RESET)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) $(INC) -o $@ -c $<

clean:
	@make -C $(LFT_PATH) clean
	@make -C $(MLX_PATH) clean
	@rm -rf $(OBJ_PATH)

fclean: clean
	@make -C $(LFT_PATH) fclean
	@rm -f $(NAME)
clean_o:
	@rm -f $(NAME)
	@rm -rf $(OBJ_PATH)

re-bis: clean_o $(NAME)

re: fclean all
