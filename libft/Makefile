# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: framdani <framdani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 02:16:17 by akhalidy          #+#    #+#              #
#    Updated: 2021/07/12 18:03:37 by framdani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re bonus

NAME = libft.a

CC = clang

SRC  = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c  \
		ft_strchr.c ft_itoa.c \
		ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
		ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_strjoin.c \
		ft_substr.c ft_strtrim.c ft_split.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		lst.c lst_2.c ft_lst_delete_node.c \
		ft_bubblesort.c ft_lst_bubblesort.c ft_arr_to_list.c  ft_is_flag.c \
		ft_strstrlen.c ft_strtolower.c ft_list_to_arr.c\
		ft_putstrstr_fd.c no_special_char.c ft_charjoin.c

OBJ  = $(SRC:.c=.o)

SRCB = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
	   ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	   ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJB  = $(SRCB:.c=.o)

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(SRC) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ):
	@$(CC) $(CFLAGS) -c $(SRC)

$(OBJB):
	@$(CC) $(CFLAGS) -c $(SRCB)

clean:
	@rm -f $(OBJ) $(OBJB)

fclean: clean
	@rm -f $(NAME)

re: fclean all

bonus : $(OBJB)
	@ar rc $(NAME) $(OBJB)
	@ranlib $(NAME)
