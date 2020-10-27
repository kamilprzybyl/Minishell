#include "minishell.h"

t_builtin       cmds_table[] =
{
    {"echo", handle_echo},
    {"pwd", handle_pwd},
    {"exit", handle_exit},
    {"cd", handle_cd},
    {"env", handle_env},
    {NULL, NULL}
};

bool exec_builtin(char **str_arr, char **envp)
{
    int     i;

    i = 0;
    while (cmds_table[i].cmd_name)
    {
        if (ft_strcmp(str_arr[0], cmds_table[i].cmd_name) == 0)
        {
            if (ft_strcmp("env", cmds_table[i].cmd_name) == 0)
                str_arr = envp;

            cmds_table[i].fct(str_arr);
            return (true);
        }
        i++;
    }
    
    return (false);
}