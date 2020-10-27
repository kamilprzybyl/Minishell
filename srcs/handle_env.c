#include "minishell.h"

void handle_env(char **args)
{
    int     i;

    i = 0;
    while (args[i])
        printf("%s\n", args[i++]);

    return;
}