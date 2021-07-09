# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: framdani <framdani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/27 20:07:22 by framdani          #+#    #+#              #
#    Updated: 2021/07/09 12:30:47 by framdani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address

LDFLAGS="-lreadline"

LIB = -L/Users/framdani/.brew/opt/readline/lib

INCLUDE = -I/Users/framdani/.brew/opt/readline/include

SRCS = main.c\
	   parser/lexer.c\
	   parser/parser.c\
	   parser/errors.c\
	   parser/expander.c\
	   parser/fill_lst_cmds.c\
	   parser/create_lst_cmds.c\
	   parser/tokenizer.c\
	   parser/free.c\
	   parser/parse_line_hd.c\
	   parser/tokenizer_utils.c\
	   parser/parse_identifier.c\
	   execution/*.c

NAME= minishell

LIBFT_PATH = ./libft/libft.a

OBJS = $(*:.c=.o)

all:$(SRCS)
	@make -C ./libft
	@gcc *.c */*.c $(LDFLAGS) $(LIB) $(INCLUDE) -o minishell  $(LIBFT_PATH)
	@echo "minishell created successfully"

clean:
	@make -C ./libft/ clean
	@cd execution && rm -rvf *.o
	@rm -f *.o

fclean:clean
	@make -C ./libft/ fclean
	@rm -rf $(NAME)
	@rm -rvf minishell.dSYM

re:fclean all

.PHONY:all clean fclean re

