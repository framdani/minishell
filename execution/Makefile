# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/08 18:54:00 by akhalidy          #+#    #+#              #
#    Updated: 2021/07/07 21:02:58 by akhalidy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = exec.a

CC = clang

CFLAG = -Wall -Wextra -Werror

LDFLAGS="-lreadline"

LIB = -L /Users/akhalidy/.brew/opt/readline/lib

INCLUDE = -I /Users/akhalidy/.brew/opt/readline/include

SRCS = ft_cd.c \
	ft_cd_outils.c \
	ft_echo.c \
	ft_env.c \
	ft_exec.c \
	ft_export.c \
	ft_pwd.c \
	ft_redirection.c \
	ft_red_help.c \
	ft_shlvl.c \
	ft_unset.c \
	ft_pipe.c \
	ft_pipe_outils.c \
	ft_launch_exec.c \
	ft_exit.c \
	ft_signals.c

OBJS = $(SRCS:.c=.o)

all:$(NAME)

$(NAME): $(SRCS) $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "exec.a created successfuly"

$(OBJS):
	@$(CC) $(CFLAGS) $(LDFLAGS) $(LIB) $(INCLUDE) -c $(SRCS)
	
clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
