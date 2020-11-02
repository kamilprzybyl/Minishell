#include "minishell.h"

void handle_pwd(__attribute__ ((unused)) char **args)
{
    char cwd[PATH_MAX];

    getcwd(cwd, sizeof(cwd));

    printf("%s\n", cwd);    // seg fault when ft_printf

    return;
}