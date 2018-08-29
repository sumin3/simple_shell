# 0x15. C - Simple Shell

A simple shell program to mimic sh shell.  It allows the user to execute commands and interact with the kernel.

## Features
* Run commands in $PATH
* Run commands from standard input

Built-ins:  
exit [status]  
env (print current environment values)  
cd  
setenv (sets environment value)  
unsetenv (clear environment value) 


## Getting Started
To use this shell, first download  this repository into your local machine by issuing the following command in your local terminal. 
```
git clone https://github.com/sumin3/simple_shell.git
```
Change directory into the simple\_shell directory created by the git clone command
and issue the following command to compile the code
```
gcc -Wall -Werror -Wextra -pedantic *.c -o shell
```
Once the files are compiled you can run the program by issuing the command
```
./shell
```
Alternatively, you can copy the shell executable into the /usr/local/bin directory by issuing
```
sudo cp shell /usr/local/bin
```
After the above has been done, you can run the program by issuing the command
```
shell
```
## Usage Examples
The following example shows how to start the shell and issue a ```ls``` command to list the contents of the directory then exit the shell
```
$ ./shell
$> ls
README.md	shell		shell_error.c		shell_helper1.c
holberton.h	shell.c		shell_get_builtin.c	shell_helper2.c
$> exit
$
```
You can also use the shell in a non-interactive mode by piping in a command as follows:
``
$ echo "/bin/ls" | ./shell
README.md	shell		shell_error.c		shell_helper1.c
holberton.h	shell.c		shell_get_builtin.c	shell_helper2.c
$
`
## Output
Command | Expected Output 
---|---
ls | lists files in current directory
/bin/ls | lists files in current directory
env | print out of environment values
ls   -l | lists files in long format
cd | changes directory to home direcotry
cd - | displays previous directory and change into tht directory
cd / | changes directory to root directory
111 | command not found 

click [here](https://docs.google.com/document/d/1H4Syxiicin9logZRJHHHy5N5iDEbLYjIQmtcaPzVo-g/edit) for a more comprehensive list of commands and expected output.  


## Testing
There is a separate repository for the test suite [Here](https://github.com/petehwu/shellgame) Follow the instructions there to run a more comprehensive test on the simple shell program.

## Files
File | Desc
---|---
AUTHORS | Authors file
README.md | Readme file
holberton.h | header file with prototypes to functions used
man\_1\_simple\_shell | man page for the simple shell program
shell.c | main entry point for the simple shell program
shell\_enviro.c | function(s) for popluating the environment values
shell\_error.c |  function(s) for handling error message printing
shell\_fork.c | function for executing command issued by user
shell\_get\_builtin.c | function(s) for handling the builtin functionality
shell\_helper1.c | helper functions
shell\_helper2.c | helper functions
shee\_set\_env.c | function(s) for setting and un-setting environment values 
## Authors
Sumin Yu    
Peter Wu
