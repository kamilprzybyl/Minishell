#ifndef _MINISHELL_H
#define _MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>                     // getcwd(), chdir()
#include <limits.h>                     // PATH_MAX
#include "../libft/includes/libft.h"

#define MAX_SIZE 2047

typedef struct       s_info_minishell
{
    int             is_echo;
    int             is_exit;
    int             is_pwd;
    int             is_cd;

}                   t_info_minishell;

void handle_echo(char **input);
void check_cmd(char *input, t_info_minishell *info);
void handle_pwd();
char **strsplit(char *str);
void handle_input(char *input, t_info_minishell *info);
void handle_exit();
void put_prompt();
void handle_cd(char *path);

#endif