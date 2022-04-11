/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** unsetenv
*/

#include <unistd.h>
#include <stdlib.h>

#include "my.h"
#include "minishell.h"
#include "my_linked_list.h"


int builtin_unsetenv(char **params, linked_list_t **env)
{
    if (my_arrlen((void **)params) <= -1) {
        builtin_env(params, env);
        return 0;
    }
    if (my_arrlen((void **)params) >= 3)
        return my_put_error("unsetenv: Too many arguments.\n");
    if (is_all_alphanum(params[1]) == 0) {
        my_put_error("unsetenv: Variable name must begin with a letter.\n");
        return 1;
    }
    return 0;
}
