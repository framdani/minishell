# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: framdani <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/21 03:41:50 by framdani          #+#    #+#              #
#    Updated: 2019/10/30 03:00:34 by framdani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRC = ft_memset.c\
	  ft_bzero.c\
	  ft_memcpy.c\
	  ft_memccpy.c\
	  ft_memmove.c\
	  ft_memchr.c\
	  ft_memcmp.c\
	  ft_strlen.c\
	  ft_strlcpy.c\
	  ft_strlcat.c\
	  ft_strchr.c\
	  ft_strrchr.c\
	  ft_strnstr.c\
	  ft_strncmp.c\
	  ft_atoi.c\
	  ft_isalpha.c\
	  no_special_char.c\
	  ft_isdigit.c\
	  ft_isalnum.c\
	  ft_isascii.c\
	  ft_isprint.c\
	  ft_toupper.c\
	  ft_tolower.c\
	  ft_strdup.c\
	  ft_calloc.c\
	  ft_substr.c\
	  ft_putendl_fd.c\
	  ft_putchar_fd.c\
	  ft_putstr_fd.c\
	  ft_strjoin.c\
	  ft_itoa.c\
	  ft_strmapi.c\
	  ft_putnbr_fd.c\
	  ft_split.c\
	  ft_strtrim.c\
		ft_lstadd_front_bonus.c\
		ft_lstclear_bonus.c\
		ft_lstdelone_bonus.c\
		ft_lstiter_bonus.c\
		ft_lstlast_bonus.c\
		ft_lstsize_bonus.c\
		get_next_line.c\
		ft_charjoin.c

OBJ = $(SRC:.c=.o)

all:$(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
clean:
	@rm -rf *.o

fclean:clean
	@rm -rf $(NAME)

re:fclean all

.PHONY: all clean fclean re bonus

