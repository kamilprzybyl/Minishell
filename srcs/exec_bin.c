#include "minishell.h"

bool exec_bin(char **str_arr)
{
    int     pid;
    char    *cmd;

    cmd = malloc(sizeof(char) * 15); 
    pid = fork();

    if (pid == -1)
        return (false);

    if (pid == 0)
    {
        ft_strcpy(cmd, "/bin/");
        ft_strcat(cmd, str_arr[0]);

        if (execve(cmd, str_arr, environ) == -1)
        {
            ft_printf("-minishell: %s: command not found\n", str_arr[0]);
            exit(0);
        }
    }
    else
        waitpid(pid, 0, 0);

    return (true);
}