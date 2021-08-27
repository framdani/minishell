## Minishell
This is a 42Network/1337 project where we have to make a mini bash. For more informations about the main instructions, [click here](https://github.com/framdani/minishell/blob/main/en.subject.pdf) .

## Grammar

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

## Build & Run the program
From your command line :
 
```
# Clone the repo
git clone https://github.com/framdani/minishell.git

# Go into the repo
cd minishell

# Build and run the program
make && ./minishell
```
## Authors
[Fatima-zahra RAMDANI](https://github.com/framdani)

[Asmaa KHALIDY](https://github.com/akh9001)


