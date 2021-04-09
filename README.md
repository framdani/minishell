# minishell

###### Task list
- [x] The difference between Bash, Zsh, and other Linux Shells.
- [x] start reading and filtering recourses.

## Notes

Shells offer a standard way of extending the command line environment. It allows us to control the computer without using the GUI.
The shell is also used in the background by various system services. Linux distributions include many functions written as shell scripts.
These scripts are commands and other advanced shell scripting functions run through the shell environment.
There are many shell environment like Bash, ash, dash, fish, and tcsh.
For more informations : (https://www.howtogeek.com/68563/htg-explains-what-are-the-differences-between-linux-shells/).

#### Basic commands

The shell that we should create must implement the builtins like in bash :

- echo  : write arguments to the standard output.
- pwd   : present working directory.
- env   : set environment and execute command, or print environment.
- unset : delete variables. 
- export
- cd
- exit

In addition to shell commands and its own arguments and options we need to deal with shell's control and redirection operators.

- (;) : List terminator, will run one command after another has finished, irrespective of the outcome of the first.
- (|) : Pipe operator, it passes the output of one command as input to another. A command built from the pipe operator is called a pipeline.
- (<) : Gives input to a command.
	```
	command < file.txt
	```
- (>) :  Directs the output of a command into a file.
	```
	command > file.txt
	```
- (>>) : Does the same as >, except that if the target file exists, the new data are appended.

	```
	command >> out.txt
	``` 

To learn more about shell's control and redirection operators : (https://unix.stackexchange.com/questions/159513/what-are-the-shells-control-and-redirection-operators).
