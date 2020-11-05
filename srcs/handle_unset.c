#include "minishell.h"

void handle_unset(char **args)
{
    int     i;
    int     len;

    i = 0;
    len = 0;

    while (environ[len])    // check enviromental elements quantity
        len++;

    while (i < len)
    {
        if (ft_strncmp(environ[i], args[1], ft_strlen(args[1])) == 0 && environ[i][(ft_strlen(args[1]))] == '=')   // check if the variable name is equal to the name passed as a argument
        {
            while (i < len)
            {
                environ[i] = environ[i+1];  // delete variable by moving each one backward (start from element with index 'i') 
                i++;
            }
            return;
        }
        i++;
    }

    return;
}