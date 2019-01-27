# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amerlon- <amerlon-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/27 05:01:06 by amerlon-          #+#    #+#              #
#    Updated: 2019/01/27 09:43:34 by amerlon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Werror -Wextra

LIBFT_DIR = ./libft
SRC_DIR = ./src
INC_DIR = ./inc
OBJ_DIR = ./obj
TEST_DIR = ./test

SRC = ft_printf.c

OBJS = $(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_H = $(LIBFT_DIR)/inc

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT) $(OBJS)
	@ar rcs $(NAME) $(OBJS) $(LIBFT)
	@ranlib $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@gcc $(FLAGS) -c $< -I$(INC_DIR) -I$(LIBFT_H) -o $@

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
	@sed 's/printf(/ft_printf(/2' test/test.c > test/test_ft.c
	@gcc $(TEST_DIR)/test.c $(NAME) $(LIBFT) -I$(INC_DIR) -I$(LIBFT_H) -o test_output_bin
	@gcc $(TEST_DIR)/test_ft.c $(NAME) $(LIBFT) -I$(INC_DIR) -I$(LIBFT_H) -o test_output_ft_bin
	@./test_output_bin > test_output
	@./test_output_ft_bin > test_output_ft
	@rm -rf test_output_bin test_output_ft_bin
	@diff -y test_output test_output_ft

diff:
	@diff -U 3 test_output test_output_ft

.PHONY: all clean fclean re norm test diff
