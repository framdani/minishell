// #include <signal.h>
// #include <readline/readline.h>
// #include <readline/history.h>
// #include <signal.h>

// void	handler(int c)
// {
// 	printf("c = %d", c);
// 	write()
// }

// int	main(void)
// {
// 	char	*cmd_line;
// 	while (1)
// 	{
// 		signal(SIGINT, handler);
// 		cmd_line = readline("minishell$ ");
// 		sleep(10);
// 		free(cmd_line);
// 	}
// 	return (0);
// }

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <readline/readline.h>
#include <unistd.h>

int a = 0;

void handler (int status)
{
	write(1, "\n", 1);
	write(1, ">> ", 3);
	write(0,"\n",1);
	a = 1;
	// rl_on_new_line();
	// rl_replace_line("",0);
	// rl_redisplay();
//    rl_done = 1;
}

int main (int argc, char** argv)
{
   char* entry;
//    printf("prompt1 : ");
   signal(SIGINT,handler);
   char *s;
//    while (1)
//    

	   write(2, "Hello\n",6);
		// entry = readline("minishell$ : ")÷;
//    }

//    printf("\nEntry was: |%s|\n", entry);
   return 0;
}