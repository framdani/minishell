CC = clang

CFLAGS = -Wall -Wextra -Werror -g

SRCS = main.c\
	   parser/lexer.c\
	   parser/parser.c\
	   parser/print_errors.c\
	   parser/expander.c\
	   parser/fill_struct_and_execute.c\
	   parser/create_pipe_sequence.c\
	   parser/draft.c\
	   parser/free.c

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
	@rm -rvf minishell.dSYM

re:fclean all

.PHONY:all clean fclean re
