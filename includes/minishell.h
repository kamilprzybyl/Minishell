#ifndef _MINISHELL_H
#define _MINISHELL_H

#include <stdio.h>
#include <stdlib.h>                     // exit()
#include <unistd.h>                     // getcwd(), chdir()
#include <limits.h>                     // PATH_MAX
#include <stdbool.h>                    // true, false, bool
#include "../Libft/includes/libft.h"

#define MAX_SIZE 2047                   // max size of input in command line


extern char **g_env;                    // my envrion

typedef struct      s_builtin
{
    char            *cmd_name;
    void            (*fct)(char **args);

}                   t_builtin;

int minishell();
int setup_g_env(char **envp);
void handle_input(char *input);
bool exec_builtin(char **tokens_tab);
bool exec_bin(char **tokens_tab);

void handle_echo(char **args);
void handle_cd(char **args);
void handle_pwd(char **args);
void handle_export(char **args);
void handle_unset(char **args);
void handle_env(char **args);
void handle_exit(char **args);

void put_prompt();

#endif
