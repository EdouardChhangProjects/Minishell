/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** builtin_cd
*/

#include <unistd.h>
#include <stdlib.h>

#include "my.h"
#include "minishell.h"
#include "my_linked_list.h"

int builtin_cd(char **params, linked_list_t **env __attribute__((unused)))
{
    if (my_arrlen((void **)params) >= 3)
        return my_put_error("cd: Too many arguments.\n");
    if (params != NULL && *params != NULL) {
        chdir(params[1]);
        return 0;
    }
    return 84;
}
