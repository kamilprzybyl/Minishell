#include "minishell.h"

void handle_echo(char **args)
{
    int     i;

    if (!args[1])
    {
        ft_putchar('\n');
        return;
    }

    i = ft_strcmp(args[1], "-n") == 0 ? 2 : 1;

    while (args[i])
    {
        ft_putstr(args[i++]);    
        if (args[i])
            ft_putchar(' ');
    }

    if (ft_strcmp(args[1], "-n") != 0)
        ft_putchar('\n');

    return;
}