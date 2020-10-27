#include "minishell.h"

void handle_cd(char **args)
{
    int     res;
    char    *home;

    if (!args[1] || (ft_strcmp(args[1], "~") == 0))
    {
        home = getenv("HOME");
        res = chdir(home);
    }
    else
        res = chdir(args[1]);

    if (res != 0)
        printf("-minishell: cd: %s: No such file or directory\n", args[1]); // seg fault when ft_printf

    return;
}