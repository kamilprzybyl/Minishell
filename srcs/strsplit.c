#include "minishell.h"

char **strsplit(char *str)
{
    char        **str_arr;
    int         words_num;
    int         i;
    int         w;
    int         c;

    words_num = ft_count_words(str, ' ');
    str_arr = malloc((words_num + 1) * sizeof(char *));
    i = 0;
    while (i != words_num)
        str_arr[i++] = malloc(256 * sizeof(char));
    str_arr[i] = NULL;

    i = 0;
    w = 0;
    while (str[i])
    {
        if (str[i] != ' ')
        {
            c = 0;
            while (str[i] != ' ' && str[i])
            {
                str_arr[w][c] = str[i];
                c++;
                i++;
            }
            w++;
        }
        else
            i++;
    }

    return (str_arr);
}