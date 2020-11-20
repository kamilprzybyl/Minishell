#include "minishell.h"

void handle_env(__attribute__ ((unused)) char **args)
{
    int     i;

    i = 0;
    while (g_env[i])
        ft_printf("%s\n", g_env[i++]);

    return;
}