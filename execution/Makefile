# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/08 18:54:00 by akhalidy          #+#    #+#              #
#    Updated: 2021/07/01 12:13:58 by akhalidy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = exec.a

CC = clang

CFLAG = -Wall -Wextra -Werror

SRCS = ft_cd.c \
	ft_echo.c \
	ft_env.c \
	ft_exec.c \
	ft_export.c \
	ft_pwd.c \
	ft_redirection.c \
	ft_shlvl.c \
	ft_unset.c \
	ft_pipe.c \
	ft_pipe_outils.c \
	ft_launch_exec.c \
	ft_exit.c

OBJS = $(SRCS:.c=.o)

all:$(NAME)

$(NAME): $(SRCS) $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "exec.a created successfuly"

$(OBJS):
	@$(CC) $(CFLAGS) -c $(SRCS)
	
clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
