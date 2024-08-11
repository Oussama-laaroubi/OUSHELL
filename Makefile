# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olaaroub <olaaroub@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/08 10:57:09 by olaaroub          #+#    #+#              #
#    Updated: 2024/08/11 21:49:02 by olaaroub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror 
# CFLAGS += -fsanitize=address -g3

SRC = src_parsing/main.c src_parsing/get_env.c src_parsing/trash.c src_parsing/split_mgem7a.c
SRC += src_parsing/tockenizing.c src_parsing/tockens_list.c
# SRC += 

OBJ = $(SRC:.c=.o)

NAME = minishell
LIB = libft/libft.a

all:  $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIB)  -lreadline -o $(NAME)

$(LIB):
	$(MAKE) -C libft

clean:
	@rm -rf $(OBJ)
	$(MAKE) clean -C libft

fclean: clean
	@rm -rf $(NAME)
	$(MAKE) fclean -C libft

re: fclean all

.PHONY: clean fclean re all bonus
.SECONDARY: $(OBJ)
