#include "minishell.h"

void handle_cd(char *path)
{
    int     res;

    res = chdir(path);

    if (res != 0)
        printf("-minishell: cd: %s: No such file or directory\n", path); // seg fault when ft_printf

    return;
}