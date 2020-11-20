#include "minishell.h"

void handle_cd(char **args)
{
    int     res;
    int     i;

    res = 0;

    if (!args[1] || (ft_strcmp(args[1], "~") == 0))
    {
        i = 0;
        while (g_env[i])
        {
            if (ft_strncmp(g_env[i], "HOME", 4) == 0 && g_env[i][4] == '=')
            {
                res = chdir(&g_env[i][5]);
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