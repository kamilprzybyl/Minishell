#include "minishell.h"

static int realloc_g_environ(int arr_size, int var_size)
{
    char        **temp;
    int         i;

    if (!(temp = malloc(sizeof(char *) * arr_size)))
        return (1);

    i = 0;
    while (i < arr_size)
    {
        if (i < (arr_size - 1))
        {
            if (!(temp[i] = malloc(sizeof(char) * (ft_strlen(g_environ[i]) + 1))))
                return (1);
            ft_strcpy(temp[i], g_environ[i]);    
        }
        else    // allocate memory for new variable
            if (!(temp[i] = malloc(sizeof(char) * (var_size + 1))))
                return (1);
        i++;
    }
    temp[i] = NULL;
    g_environ = temp;

    return (0);
}

static void add_env_var(char *arg)
{
    realloc_g_environ((ft_arrlen(g_environ) + 1), ft_strlen(arg));
    ft_strcpy(g_environ[(ft_arrlen(g_environ) - 1)], arg);     // create new variable
    
}

static void ovr_env_var(char *arg)
{
    int         len;
    int         i;

    len = 0;
    i = 0;

    while (arg[len])    // find '=' character index and save it in 'len' variable
    {
        if (arg[len] == '=')
            break;
        len++;
    }

    while (g_environ[i])
    {
        if (ft_strncmp(g_environ[i], arg, len) == 0 && g_environ[i][len] == '=')
        {
            ft_bzero(g_environ[i], ft_strlen(g_environ[i]));
            ft_strcpy(g_environ[i], arg);
            return;
        }
        i++;
    }    
}

void handle_export(char **args)
{
    int         i;

    i = 1;
    while (args[i])
    {
        if (ft_strchr(args[i], '=') == NULL)
            return;        

        ovr_env_var(args[i]);  // when it requires to overwrite variable
    
        add_env_var(args[i]);  // when you want to creaete new one   

        i++;
    } 
}
