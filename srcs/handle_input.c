#include "minishell.h"

void handle_input(char *input, char **envp)
{
    char        **str_arr;

    if (ft_strlen(input) == 0)
        return;

    str_arr = ft_strsplit(input);  // tokenization process

    if ((exec_builtin(str_arr, envp) == false) && (exec_bin(str_arr, envp) == false))
        printf("-minishell: %s: command not found\n", str_arr[0]);                      // bus error when ft_printf
    
    return;
}