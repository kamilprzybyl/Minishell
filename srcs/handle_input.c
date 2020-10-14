#include "minishell.h"

void handle_input(char *input, t_info_minishell *info)
{
    char        **str_arr;
    // int         i;

    str_arr = strsplit(input);  // tokenization process

    check_cmd(str_arr[0], info);

    if (info->is_echo)
        handle_echo(str_arr);
    else if (info->is_pwd)
        handle_pwd();
    else if (info->is_exit)
        handle_exit();
    else if (info->is_cd)
        handle_cd(str_arr[1]);

    // i = 0;
    // while (str_arr[i])
    //     free(str_arr[i]);

    return;
}