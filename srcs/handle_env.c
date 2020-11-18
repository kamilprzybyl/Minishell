#include "minishell.h"

void handle_env(__attribute__ ((unused)) char **args)
{
    int     i;

    i = 0;
    while (g_environ[i])
        ft_printf("%s\n", g_environ[i++]);

    return;
}