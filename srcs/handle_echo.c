#include "minishell.h"

void handle_echo(char **args)
{
    int     i;

    if (!args[1])
    {
        ft_putchar('\n');
        return;
    }

    i = ft_strcmp(args[1], "-n") == 0 ? 2 : 1;  // if '-n' was passed skip that argument and set 'i' to 2

    while (args[i])
    {
        if (args[i][0] == '$')  // when user demands env variable
        {
            if (ft_getenv(&args[i][1]))
                ft_printf("%s", ft_getenv(&args[i][1]));
            i++;
        }
        else     
            ft_putstr(args[i++]); // when we have to print just some string

        if (args[i])    // if it's not the last argument put space character after argument
            ft_putchar(' ');
    }

    if (ft_strcmp(args[1], "-n") != 0)  // if '-n' wasn't passed make new line at the end of result
        ft_putchar('\n');

    return;
}