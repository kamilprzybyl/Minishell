#include "minishell.h"

char **g_env;

int main(int argc, char **argv, char **envp)
{
    (void)argc;
    (void)argv;
    
    setup_g_env(envp);
    minishell();

    return (0);
}