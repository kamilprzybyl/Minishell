#include "minishell.h"

bool exec_bin(char **tokens_tab)
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
        ft_strcat(cmd, tokens_tab[0]);

        if (execve(cmd, tokens_tab, g_env) == -1)
        {
            ft_printf("-minishell: %s: command not found\n", tokens_tab[0]);
            exit(0);
        }
    }
    else
        waitpid(pid, 0, 0);

    return (true);
}