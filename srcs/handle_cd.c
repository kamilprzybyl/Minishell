#include "minishell.h"

void handle_cd(char **args)
{
    int     res;
    int     i;

    res = 0;

    if (!args[1] || (ft_strcmp(args[1], "~") == 0))
    {
        i = 0;
        while (environ[i])
        {
            if (ft_strncmp(environ[i], "HOME", 4) == 0 && environ[i][4] == '=')
            {
                res = chdir(&environ[i][5]);
                return;
            }
            i++;
        }
    }
    else
        res = chdir(args[1]);

    if (res != 0)
        ft_printf("-minishell: cd: %s: No such file or directory\n", args[1]);

    return;
}