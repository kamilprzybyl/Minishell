#include "minishell.h"

static int unset(char *arg)
{
    int         i;
    int         g_env_len;
    int         arg_len;

    i = 0;
    g_env_len = ft_arrlen(g_env);
    arg_len = ft_strlen(arg);
    
    while (i < g_env_len)
    {
        /* find variable to unset */
        if (!ft_strncmp(g_env[i], arg, arg_len) && g_env[i][arg_len] == '=')
        {
            /* delete variable by moving each one backward to overlap it */
            while (i < g_env_len)
            {
                g_env[i] = g_env[i+1];
                i++;
            }
            return (0);
        }
        i++;
    }
    return (1);
}

void handle_unset(char **args)
{
    int     i;

    i = 0;
    while (args[i])
    {
        unset(args[i]);
        i++;
    }

    return;
}