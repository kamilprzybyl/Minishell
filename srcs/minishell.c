#include "minishell.h"

void init_variable(t_info_minishell *info)
{
    info->is_echo = 0;
    info->is_exit = 0;
    info->is_pwd = 0;
    info->is_cd = 0;
}

int main(int __attribute__ ((unused)) argc, __attribute__ ((unused)) char **argv)
{
    t_info_minishell    info;
    char                *input;
    int                 ret;

    input = malloc(256 * sizeof(char));

    put_prompt();
    while ((ret = read(STDIN_FILENO, input, MAX_SIZE)))
    {
        input[ret-1] = '\0';    // read function returns \n a the end of the string, we don't need it so we set it to NULL

        init_variable(&info);
        
        handle_input(input, &info);

        bzero(input, strlen(input));
        
        put_prompt();
    }

    return (0);
}