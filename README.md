# Minishell

The objective of this project is to create a simple shell.

<br />

## General

1. It's behaviour is almost identical to shell


2. It shows a prompt when waiting for a new command


3. It contains a few recoded builtin functions as follows
  * `echo`
  * `cd`
  * `pwd`
  * `export`
  * `unset`
  * `env`
  * `exit`


4. It search and launch the right executable (based on the PATH variable or by using relative or absolute path)


5. `;` works like in shell


<br />

## Setup

```
$ git clone git@github.com:kamilprzybyl/minishell.git
$ cd minishell
$ make
$ ./minishell
```

