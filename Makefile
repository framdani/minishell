CC = clang

CFLAGS = -Wall -Wextra -Werror -fsanitize=address

SRCS = main.c\
	   lexer.c\
	   parser.c\
	   print_errors.c\
	   expander.c\
	   fill_struct_and_execute.c\
	   create_pipe_sequence.c\
	   initialize.c

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
