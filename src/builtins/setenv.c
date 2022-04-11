/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** setenv
*/


#include <unistd.h>
#include <stdlib.h>

#include "my.h"
#include "minishell.h"
#include "my_linked_list.h"

int builtin_setenv(char **params, linked_list_t **env)
{
    char *arg = "\0";

    if (my_arrlen((void **)params) <= 1)
        return builtin_env(params, env);
    if (my_arrlen((void **)params) >= 4)
        return my_put_error("setenv: Too many arguments.\n");
    if (is_all_alphanum(params[1]) == 0) {
        my_put_error("setenv: Variable name must begin with a letter.\n");
        return 1;
    }
    if (my_arrlen((void **)params) == 3)
        arg = params[2];
    add_end_node(envcat(params[1], arg), env);
    return 0;
}
