## Minishell
This is a 42Network/1337 project where we have to make a mini bash. For more informations about the main instructions, [click here](https://github.com/framdani/minishell/blob/main/en.subject.pdf) .

## Grammar

Grammar is the set of rules by which the words in a computer statement are interpreted into meaningful machine instructions.
The grammar below represents the syntax rules of this mini bash.

```
pipeline         : pipe_sequence
                 ;
pipe_sequence    : command
                 | pipe_sequence '|' command
                 ;
command          : simple_command
                 ;
simple_command   : cmd_prefix cmd_word cmd_suffix
                 | cmd_prefix cmd_word
                 | cmd_prefix
                 | cmd_name cmd_suffix
                 | cmd_name
                 ;
cmd_name         : WORD                 
                 ;
cmd_word         : WORD              
                 ;
cmd_prefix       :            io_redirect
                 | cmd_prefix io_redirect
                 |            ASSIGNMENT_WORD
                 | cmd_prefix ASSIGNMENT_WORD
                 ;
cmd_suffix       :            io_redirect
                 | cmd_suffix io_redirect
                 |            WORD
                 | cmd_suffix WORD
                 ;
redirect_list    :               io_redirect
                 | redirect_list io_redirect
                 ;
io_redirect      :           io_file
                 |           io_here
                 ;
io_file          : '<'       filename
                 | '>'       filename
                 | DGREAT    filename
                 | LESSGREAT filename
                 ;
filename         : WORD                     
                 ;
io_here          : DLESS     here_end
                 ;
here_end         : WORD 
                 ;
```

## Execution
The execution part consists of changing the standard (0 and 1) file descriptors to another one in the existance of a redirection or a pipe then checking if the command given is either a builtin command or an executable file in the path environment variable and save the exit status/code of that executed command.


## Build & Run the program
From your command line :
 
```
# Clone the repo
git clone https://github.com/framdani/minishell.git

# install readline :
 brew install readline #In your compilation, append these flags: -lreadline -L /Users/$(USER)/.brew/opt/readline/lib -I/Users/$(USER)/.brew/opt/readline/include

# Go to the root directory
cd minishell

# Build and run the program
make && ./minishell
```
## Authors
[Fatima-zahra RAMDANI](https://github.com/framdani)

[Asmaa KHALIDY](https://github.com/akh9001)


