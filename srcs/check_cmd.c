#include "minishell.h"

void check_cmd(char *cmd ,t_info_minishell *info)
{
    if (ft_strcmp(cmd, "echo") == 0)
        info->is_echo = 1;
    else if (ft_strcmp(cmd, "exit") == 0)
        info->is_exit = 1;
    else if (ft_strcmp(cmd, "pwd") == 0)
        info->is_pwd = 1;
    else if (ft_strcmp(cmd, "cd") == 0)
        info->is_cd = 1;
    else
        printf("-minishell: %s: command not found\n", cmd); // bus error when ft_printf

    return;
}