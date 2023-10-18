# ALX Shell - a simple shell

##### ALX Shell (hsh) is a simple command line shell for OS X and Linux. Hsh includes most basic features present in the bash shell. This shell was built as a project for ALX School.

#### Quick Start

------

HSH works like any other shell, like bash or zsh. Detailed user documentation on specific commands is available by running help within hsh.

HSH builds successfully with a GCC 4.8.5 compiler or later. HSH can compile using `gcc 4.8.4 -Wall -Werror -Wextra -pedantic *.c -o simple_shell`.

To start up HSH, simply type in 
```
./simple_shell
``` 
the terminal.

#### Syntax Overview

------

Like other shells, hsh is used by given it commands. Every hsh command follows the same general syntax: `command name {arguments}`. The command is executed by writing the name of the command followed by any arguements. 

```
echo Hello ALX
```

Above will run the `echo` command, which will write its arguements `Hello ALX` to  the standard output. 

For more information on echo, you can use the `man` command. The `man` command displays a manual page of a given command, system call, libraries, and important files. 

```
man echo
```

The hsh shell also provides various builtins, commands built into the hsh shell itself. For more information on specific builtins, you can use the `help` command, which provides a similar manual for the specific builtin.

```
help setenv
```

Supported syntax and lists of builtins and commands are given in their respected sections. 

#### Commands

------

Any program in your computer can be used as a command in hsh. If the program is located in any of the directories in the [PATH - link include], then typing the filename is enough to run the command. Otherwise, a full path to the program is required

```
/Desktop/ALX/my_echo Hello ALX
```

##### Command Seperation 

Commands and any arguments are seperated by a ` ' '` . Commands end with either a newline (i.e Return Key) or a `;`, `&&`, or `||`.  

To enter more than one command in one line, a `;` can be used to seperate commands. Commands are read and executed left to right.

```
echo Hello ALX ; ls
```

If commands are seperated by `&&` , the leftmost command is read and executed and if the execution failed, no other commands are executed, otherwise, the next command in line will be executed. If the commands is seperated by `||` , regardless of execution failure or success of the leftmost command, all suceeded commands are executed. 

##### Switches & Flags

Switches and flags arguements of commands are also supported by hsh. Most switches start with a hypen, `-`  and always somehows affect the command in one way. For example, when a user inputs:

```
ls -a
```

The `ls` commands lists all directories and files in the current working directory. However, including the switch `-a` , will also include all files and directories, including hidden ones. 

##### Comments

hsh provides support for comments added into standard input. Comments can be inputed by placing a `#` before any statement. Comments are ignored by hsh. 

```
echo # Hello ALX
```

The above command will not write Hello ALX to standard output.

##### List of useful commands

`cat` - concatenate and print files to standout output

`cp` - copy files to another file

`grep` - searches a file for a specified pattern

`less` - allows backward moveement in the file as well as foward movement

`ls` - lists all files and directories of current working directory

`mv` - moves one file into another file

`pwd` - prints out the current working directory

#### Builtins 

------

There are several builtins programmed into the hsh. Below is a description and use for each builtin.

##### env, setenv, unsetenv

To print out a list of all the environemental variables, the builtin `env` can be used. Each environmental variable and its value is printed out with a syntax of `key=value`. Each variable is seperated by a new line. 

To set an environemental variable, the builtin is `setenv`. The syntax to use `setenv` is `setenv key value`. If one of the arguments is missing, an error is returned. 

```
setenv ALX betty
```

To remove an environemental variable, the builtin `unsetenv` can be used. The syntax to use `unsetenv` is `unsetenv key`. If no `key` value is given, an error is returned.

```
unsetenv ALX
```

##### cd

The `cd` command changes the shell working directory. The syntax to use the command is `cd DIR`. If no `DIR` is given, it is defaulted to the HOME shell variable. The full path of the directory is needed. To change the directory to its parent, the argument `..` can be used. 

##### history

To print out a list of previous commands used, the command `history` can be used. The previous 50 commands will be printed out. The history of all commands is written into the `.simple_shell_history` file.

##### help

To receive a description and the syntax use of a specific command, you can use the `help` command. To use the `help` builtin, the synatax is as follows 

```
help cd
```

The output would include usage followed by a definition.

```
cd usage: cd DIR
	Change the current directory to DIR
```

##### exit

To exit out of the shell, the user may use the `exit` builtin. To use `exit`, a status number, `n` can be given. If `n` is ommited, the exit status is that of the last command executed.

```
exit 1
```

#### Exiting commands and hsh

------

To exit out of a process or command, `ctrl c` is used. Control-C interrupts a process and causes it to abort.

To exit out of the hsh shell, the user can do one of the following, `ctrl D` or `exit n`. When exiting with `ctrl D`, an exit status of 0 is given. Using `exit`, you can input its exit status or it is defaulted to the status of the last command executed. 


