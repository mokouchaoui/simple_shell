### Description
**A simple UNIX command interpreter.**
simple_shell is the user interface to communicate with the operative system services, and also, has his own language (scripting language) called bash scripting , all of this are built in C (C, not C++ ;) ) under the hood.

### Requirements
* Gcc (gnu compiler collection) version 4+

### Included .c source code
* simple_shell.h - For prototypes
* simple__shell.c - main code for the simple_shell
* ctrlc.c - source code for avoid the ctrl+c
* exit.c - source code for implement the exit function

### Compiling
```
gcc -g -Wall -Werror -Wextra -pedantic *.c -o hsh
```
### Running
```
./shell
```
### Output
For now simple_shell only run with single commands without arguments and you need to specify the folder.

##### Example:
```
$ /bin/ls
```
for list the files in the current directory or

```
$ /bin/pwd
```
for display the current directory address

### How to exit
You have two forms to exit from simple_shell, just type exit
```
$ exit
```
You can press CTRL + d
```
$ ./shell: Success
```
