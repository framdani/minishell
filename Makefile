# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: framdani <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/27 20:07:22 by framdani          #+#    #+#              #
#    Updated: 2021/06/27 20:07:24 by framdani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

CFLAGS = -Wall -Wextra -Werror -g

SRCS = main.c\
	   parser/lexer.c\
	   parser/parser.c\
	   parser/print_errors.c\
	   parser/expander.c\
	   parser/fill_struct_and_execute.c\
	   parser/create_lst_cmds.c\
	   parser/draft.c\
	   parser/free.c

NAME= minishell

LIBFT_PATH = ./libft/libft.a

EXEC_PATH = ./execution/exec.a

#PARSER_PATH = ./parser/parser.a

OBJS = $(SRCS:.c=.o)

all:$(SRCS)
	@make -C ./libft
	@make -C ./execution
	@$(CC) $(CFLAGS) $(SRCS) -o minishell $(LIBFT_PATH) $(EXEC_PATH)
	@echo "minishell created successfully"

clean:
	make -C ./libft/ clean
	make -C ./execution/ clean
	@rm -f *.o

fclean:clean
	make -C ./libft/ fclean
	make -C ./execution/ fclean
	@rm -rf $(NAME)
	@rm -rvf minishell.dSYM

re:fclean all

.PHONY:all clean fclean re
