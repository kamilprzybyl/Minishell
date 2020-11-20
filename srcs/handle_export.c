#include "minishell.h"

static int realloc_g_env(int arr_size, int var_size)
{
    int         i;
    char        **temp;

    if (!(temp = malloc(sizeof(char *) * arr_size)))
        return (1);

    i = 0;
    while (i < arr_size)
    {
        if (i < (arr_size - 1))
        {
            if (!(temp[i] = malloc(sizeof(char) * (ft_strlen(g_env[i]) + 1))))
                return (1);
            ft_strcpy(temp[i], g_env[i]);    
        }
        else    // allocate memory for new variable
            if (!(temp[i] = malloc(sizeof(char) * (var_size + 1))))
                return (1);
        i++;
    }
    temp[i] = NULL;
    g_env = temp;

    return (0);
}

static int add_env_var(char *arg)
{
    int         g_env_len;
    int         arg_len;

    g_env_len = ft_arrlen(g_env);
    arg_len = ft_strlen(arg);

    realloc_g_env((g_env_len + 1), arg_len);
    ft_strcpy(g_env[(g_env_len - 1)], arg); // create variable
    
    return (0);
}

static int ovr_env_var(char *arg)
{
    int         i;
    int         equals_idx;

    i = 0;
    equals_idx = ft_charidx(arg, '=');
    
    while (g_env[i])
    {
        /* find variable to overwrite */
        if (!ft_strncmp(g_env[i], arg, equals_idx) && g_env[i][equals_idx] == '=')
        {
            /* overwrite variable */
            ft_bzero(g_env[i], ft_strlen(g_env[i]));
            ft_strcpy(g_env[i], arg);
            return (0);
        }
        i++;
    }  

    return (1);  
}

void handle_export(char **args)
{
    int         i;

    i = 1;
    while (args[i])
    {
        if (ft_strchr(args[i], '=') == NULL)
            return;        

        /* if user doesn't want to overwrite existing var., create new one */
        if (ovr_env_var(args[i]) != 0)
            add_env_var(args[i]);

        i++;
    } 
}
