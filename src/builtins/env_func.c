/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** env
*/

#include <unistd.h>
#include <stdlib.h>

#include "my.h"
#include "minishell.h"
#include "my_linked_list.h"

int is_all_alphanum(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (!((str[i] >= '0' && str[i] <= '9') || \
(str[i] >= 'a' && str[i] <= 'z') || \
(str[i] >= 'A' && str[i] <= 'Z')))
            return 0;
    return 1;
}

char *envcat(char *env, char *value)
{
    char *dest = my_memset(sizeof(char) * \
(my_strlen(env) + my_strlen(value) + 2), NULL);
    int len = my_strlen(env);

    my_strcpy(dest, env);
    if (env[len - 1] != '=')
        dest[len++] = '=';
    my_strcpy(&dest[len], value);
    return dest;
}

int builtin_env(char **params, linked_list_t **env)
{
    if (my_arrlen((void **)params) == 1) {
        my_show_linked_list(*env);
        return 0;
    } else {
        return 125;
    }
}
