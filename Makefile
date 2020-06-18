# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdussert <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/29 07:50:24 by hdussert          #+#    #+#              #
#    Updated: 2018/05/18 11:23:44 by hdussert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLUE = '\033[1;34m'
PURPLE = '\033[0;35m'
LPURPLE = '\033[1;35m'
LGREEN = '\033[1;4;32m'
END = '\033[0m'

NAME = fractol

SRC_PATH = src
SRC_NAME = main.c \
		   draw.c \
		   events.c \
		   error.c \
		   my_math.c

OBJ_PATH = obj
OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

INC_PATH = include minilibx_macos
INC_FLAG = $(addprefix -I,$(INC_PATH))

LBFTFLAGS = -Llibft -lft

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LBXFLAGS = -Lminilibx_macos -lmlx
FWFLAGS = -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@echo $(BLUE)"Libft ❖"$(END)
	@echo ""$(PURPLE)
	@make -C minilibx_macos/
	@echo $(LPURPLE)"MLX ❖"$(END)
	@$(CC) $^ -o $(NAME) $(FWFLAGS) $(LBXFLAGS) $(LBFTFLAGS)
	@echo $(LGREEN)"\nFractol ❖"$(END)
	@$(CC) $^ -o $(NAME) $(FWFLAGS) $(LBXFLAGS) $(LBFTFLAGS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC_FLAG) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@make -C libft/ fclean
	@make -C minilibx_macos/ clean
	@rm -f $(NAME)

re: fclean all

o2: CFLAGS += -o2
o2: re

o3: CFLAGS += -o3
o3: re

norme:
	norminette $(SRC)
	norminette $(INC_PATH)/*.h

