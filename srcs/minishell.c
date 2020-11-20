#include "minishell.h"

int minishell()
{
    char        *input;
    int         ret;

    input = malloc(MAX_SIZE * sizeof(char));

    put_prompt();
    while ((ret = read(STDIN_FILENO, input, MAX_SIZE)))
    {
        /* read function returns the string with \n,
           we want it without \n so we set it to NULL */
        input[ret-1] = '\0';

        handle_input(input);

        bzero(input, strlen(input));
        
        put_prompt();
    }    
}