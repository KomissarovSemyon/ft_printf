# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/27 05:01:06 by amerlon-          #+#    #+#              #
#    Updated: 2019/02/03 17:23:11 by amerlon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Werror -Wextra

LIBFT_DIR = ./libft
SRC_DIR = ./src
INC_DIR = ./inc
OBJ_DIR = ./obj
TEST_DIR = ./test

SRC		=	ft_printf.c \
			token_processing.c \
			print_char.c \
			print_string.c \
			print_pointer.c \
			print_decimal.c \
			print_number.c \
			print_octal.c

OBJS = $(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_H = $(LIBFT_DIR)/inc

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@make -C libft

$(NAME): $(OBJ_DIR) $(LIBFT) $(OBJS)
	ar rcs $(NAME) $(OBJS) $(LIBFT_DIR)/obj/*.o
	@ranlib $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	gcc -g $(FLAGS) -c $< -I$(INC_DIR) -I$(LIBFT_H) -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@make -C libft clean

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean

re: fclean all

norm:
	@make -C libft norm
	@norminette $(SRC_DIR) $(INC_DIR)

test:
	./test/check.py --path libftprintf.a --header libft/inc/libft.h --file test/test_input.txt

retest: all test

main:
	gcc -g main.c libftprintf.a -Ilibft/inc -Iinc && ./a.out


.PHONY: all clean fclean re norm test retest main
