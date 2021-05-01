CC = clang

CFLAGS = -Wall -Wextra -Werror

SRCS = main.c\
	   lexer.c

NAME= minishell

OBJS = $(SRCS:.c=.o)

all:$(SRCS)
	@make -C ./libft
	@$(CC) $(CFLAGS) -o minishell $(SRCS) -I -L ./libft/libft.a
	@echo "minishell created successfully"

clean:
	@cd libft && make clean
	@rm -f *.o

fclean:clean
	@cd libft && make fclean
	@rm -rf $(NAME)

re:fclean all

.PHONY:all clean fclean re
