/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** get_params
*/

#include <stdlib.h>

#include "my.h"
#include "minishell.h"
#include "my_linked_list.h"

char **clean_str(char **str)
{
    int index = 0;

    for (index = 0; str[index] != NULL; index++);
    return str;
}

char **get_params(char *str)
{
    char **params = NULL;

    str[my_strlen(str) - 1] = '\0';
    params = str_to_array(str, ' ');
    params = clean_str(params);
    return params;
}

void free_params(char **params)
{
    for (int i = 0; params[i] != NULL; i++)
        free(params[i]);
    free(params);
}

char **get_path(linked_list_t *env)
{
    char *tmp = NULL;
    char **path = NULL;

    for (; env != NULL; env = env->next)
        if (my_strncmp((char *)(env->data), "PATH=", 5) == 0)
            tmp = &(((char *)(env->data))[5]);
    path = str_to_array(tmp, ':');
    if (path == NULL) {
        path = my_memset(sizeof(char *) * 2, NULL);
        if (path == NULL)
            return NULL;
        path[0] = my_strdup("/usr/bin/");
    }
    return path;
}

char *format_params(char **params, linked_list_t *env)
{
    int index = 0;
    char **path = NULL;
    char *filename = NULL;

    if (**params == '.' && (*params)[1] == '/')
        return my_strdup(&(*params)[2]);
    if (is_exec(*params) == 1)
        return my_strdup(*params);
    if ((path = get_path(env)) == NULL)
        return NULL;
    while (path[index] != NULL && is_exec(filecat(path[index], *params)) == 84)
        index++;
    if (path[index] == NULL)
        return NULL;
    filename = filecat(path[index], *params);
    free_array((void **)path);
    return filename;
}
