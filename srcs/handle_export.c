#include "minishell.h"

void handle_export(char **args)
{
    int     i;

    i = 0;

    if (ft_strchr(args[1], '=') == NULL)
        return;

    while (environ[i])
        i++;
    
    environ[i] = malloc(sizeof(char) * (ft_strlen(args[1]) + 1));
    environ[i+1] = NULL;

    ft_strcpy(environ[i], args[1]);

    return;    
}