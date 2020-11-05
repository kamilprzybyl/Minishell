#include "minishell.h"

void handle_pwd(__attribute__ ((unused)) char **args)
{
    char cwd[PATH_MAX];

    getcwd(cwd, sizeof(cwd));

    ft_printf("%s\n", cwd);

    return;
}