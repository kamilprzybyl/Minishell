#include "minishell.h"

void handle_input(char *input)
{
    char        **tokens_tab;
    char        **cmd_tab;

    if (ft_strlen(input) == 0)  // if input contains only tab, space or new line characters
        return;                     // go to next line and start reading an input again

    cmd_tab = ft_strsplit(input, ';');      // separate commands by semicolons

    int i = 0;
    while (cmd_tab[i])      // run 'i' commands one by one
    {
        tokens_tab = ft_strsplit(cmd_tab[i], ' ');     // tokenization process

        if (tokens_tab[0] == NULL)
            return;    

        if ((exec_builtin(tokens_tab) == false))   // check if the command is equal to the ones in "exec_builtin" and execute it, otherwise execute from "bin/" path
            exec_bin(tokens_tab); 

        i++;
    }
    return;
}