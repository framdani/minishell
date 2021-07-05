# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/27 20:07:22 by framdani          #+#    #+#              #
#    Updated: 2021/07/05 14:47:13 by akhalidy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address

LDFLAGS="-lreadline"

SRCS = main.c\
	   parser/lexer.c\
	   parser/parser.c\
	   parser/errors.c\
	   parser/expander.c\
	   parser/fill_struct_and_execute.c\
	   parser/create_lst_cmds.c\
	   parser/tokenizer.c\
	   parser/free.c\
	   parser/parse_line_hd.c\
	   parser/lexer_utils.c

NAME= minishell

LIBFT_PATH = ./libft/libft.a

EXEC_PATH = ./execution/exec.a

#PARSER_PATH = ./parser/parser.a

OBJS = $(SRCS:.c=.o)

all:$(SRCS)
	@make -C ./libft
	@make -C ./execution
	@$(CC) $(CFLAGS) -g $(LDFLAGS) $(SRCS) -o minishell $(LIBFT_PATH) $(EXEC_PATH)
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

