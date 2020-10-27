#include "minishell.h"


int main(int __attribute__ ((unused)) argc, __attribute__ ((unused)) char **argv, char **envp)
{
    char                *input;
    int                 ret;

    input = malloc(MAX_SIZE * sizeof(char));

    put_prompt();
    while ((ret = read(STDIN_FILENO, input, MAX_SIZE)))
    {
        input[ret-1] = '\0';    // read function returns \n a the end of the string, we don't need it so we set it to NULL

        handle_input(input, envp);

        bzero(input, strlen(input));
        
        put_prompt();
    }

    return (0);
}