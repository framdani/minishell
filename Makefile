# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: framdani <framdani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/27 20:07:22 by framdani          #+#    #+#              #
#    Updated: 2021/07/12 18:14:39 by framdani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

CFLAGS = -Wall -Wextra -Werror

LDFLAGS="-lreadline"

LIB = -L/Users/$(USER)/.brew/opt/readline/lib

INCLUDE = -I/Users/$(USER)/.brew/opt/readline/include

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
	   parser/parse_stop_word.c\
	   execution/ft_cd_outils.c\
	   execution/ft_cd.c\
	   execution/ft_echo.c\
	   execution/ft_env.c\
	   execution/ft_exec.c\
	   execution/ft_exit.c\
	   execution/ft_export.c\
	   execution/ft_launch_exec.c\
	   execution/ft_path.c\
	   execution/ft_pipe_outils.c\
	   execution/ft_pipe.c\
	   execution/ft_pwd.c\
	   execution/ft_red_help.c\
	   execution/ft_redirection.c\
	   execution/ft_shlvl.c\
	   execution/ft_signals.c\
	   execution/ft_unset.c
	   
NAME = minishell

LIBFT_PATH = ./libft/libft.a

OBJS = $(SRCS:.c=.o)

all:$(SRCS)
	@make -C ./libft
	@$(CC) $(CFLAGS) $(SRCS) $(LDFLAGS) -ltermcap $(LIB) $(INCLUDE) -o minishell  $(LIBFT_PATH)
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

