#include "minishell.h"

void handle_input(char *input)
{
    char        **str_arr;
    char        **cmd_arr;

    if (ft_strlen(input) == 0)
        return;

    cmd_arr = ft_strsplit(input, ';');      // separate commands by semicolons

    int i = 0;
    while (cmd_arr[i])      // run 'i' commands one by one
    {
        str_arr = ft_strsplit(cmd_arr[i], ' ');     // tokenization process

        if (str_arr[0] == NULL)
            return;    

        if ((exec_builtin(str_arr) == false) && (exec_bin(str_arr) == false))   // check if the command is equal to the ones in "exec_builtin" and execute it, otherwise execute from "bin/" path
            printf("-minishell: %s: command not found\n", cmd_arr[i]);                      // bus error when ft_printf

        i++;
    }
    return;
}