#include "minishell.h"

int setup_g_environ(char **envp)
{
    int         i;

    i = 0;

    if (!(g_environ = malloc(sizeof(char *) * (ft_arrlen(envp) + 1))))
        return (1);

    while (envp[i])
    {
        if(!(g_environ[i] = malloc(sizeof(char) * (ft_strlen(envp[i]) + 1))))
            return (1);
        ft_strcpy(g_environ[i], envp[i]);
        i++;
    }
    g_environ[i] = NULL;

    return (0);
}