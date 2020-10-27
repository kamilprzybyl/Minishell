#include "minishell.h"

bool exec_bin(char **str_arr, char **envp)
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

        if (execve(cmd, str_arr, envp) == -1)
            return (false);
    }
    else 
        waitpid(pid, 0, 0);

    return (true);
}