#ifndef _MINISHELL_H
#define _MINISHELL_H

#include <stdio.h>
#include <stdlib.h>                     // exit()
#include <unistd.h>                     // getcwd(), chdir()
#include <limits.h>                     // PATH_MAX
#include <stdbool.h>                    // true, false, bool
#include "../libft/includes/libft.h"

#define MAX_SIZE 2047

typedef struct      s_builtin
{
    char            *cmd_name;
    void            (*fct)(char **args);

}                   t_builtin;

void handle_input(char *input, char **envp);
bool exec_builtin(char **str_arr, char **envp);
bool exec_bin(char **str_arr, char **envp);
void handle_echo(char **args);
void handle_pwd();
void handle_cd(char **args);
void handle_env(char **args);
void handle_exit();
void put_prompt();

#endif
