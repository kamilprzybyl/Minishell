# Minishell

The objective of this project is to create a simple shell.

<br />

## General

It's behaviour is almost identical to shell

<br />

1. It shows a prompt when waiting for a new command

2. It contains a few recoded builtin functions as follows
   - `echo`
   - `cd`
   - `pwd`
   - `export`
   - `unset`
   - `env`
   - `exit`

3. It search and launch the right executable (based on the PATH variable or by using relative or absolute path)

4. `;` separate commands like in shell

<br />

## Setup

```
$ git clone git@github.com:kamilprzybyl/minishell.git
$ cd minishell
$ make
$ ./minishell
```

