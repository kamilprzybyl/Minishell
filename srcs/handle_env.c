#include "minishell.h"

void handle_env(char **envp)
{
    int     i;

    i = 0;
    while (envp[i])
        printf("%s\n", envp[i++]);
        
    return;
}