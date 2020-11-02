#include "minishell.h"

void handle_export(char **args)
{
    int     len;
    int     i;

    len = 0;

    if (ft_strchr(args[1], '=') == NULL)
        return;

    while (args[1][len])    // find '=' character index and save it in 'len' v variable
    {
        if (args[1][len] == '=')
            break;
        len++;
    }

    i = 0;
    while (environ[i])  // when it requires to overwrite variable
    {
        if (ft_strncmp(environ[i], args[1], len) == 0 && environ[i][len] == '=')
        {
            ft_bzero(environ[i], ft_strlen(environ[i]));
            ft_strcpy(environ[i], args[1]);
            return;
        }
        i++;
    }

    i = 0;
    while (environ[i])  // when you want to create a new variable
        i++;
    
    environ[i] = malloc(sizeof(char) * (ft_strlen(args[1]) + 1));
    environ[i+1] = NULL;

    ft_strcpy(environ[i], args[1]);

    return;    
}