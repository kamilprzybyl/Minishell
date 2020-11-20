#include "minishell.h"

int setup_g_env(char **envp)
{
    int         i;

    i = 0;

    if (!(g_env = malloc(sizeof(char *) * (ft_arrlen(envp) + 1))))
        return (1);

    while (envp[i])
    {
        if(!(g_env[i] = malloc(sizeof(char) * (ft_strlen(envp[i]) + 1))))
            return (1);
        ft_strcpy(g_env[i], envp[i]);
        i++;
    }
    g_env[i] = NULL;

    return (0);
}