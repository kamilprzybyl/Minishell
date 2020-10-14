#include "minishell.h"

void handle_echo(char **input)
{
    int     i;

    i = ft_strcmp(input[1], "-n") == 0 ? 2 : 1;

    while (input[i])
    {
        ft_putstr(input[i++]);    
        if (input[i])
            ft_putchar(' ');
    }

    if (ft_strcmp(input[1], "-n") != 0)
        ft_putchar('\n');

    return;
}