/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** cd
*/

#include <unistd.h>
#include <stdlib.h>

#include "my.h"
#include "minishell.h"
#include "my_linked_list.h"

const char *commands[] = {
    "cd",
    "env",
    "setenv",
    "unsetenv",
    NULL
};

int (*builtin_func[])(char **, linked_list_t **) = {
        builtin_cd,
        builtin_env,
        builtin_setenv,
        builtin_unsetenv,
};

int check_builtin(char *str, char **params, linked_list_t **env)
{
    for (int i = 0; i < my_arrlen((void **)commands); i++) {
        if (my_strcmp(commands[i], str) == 0) {
            return builtin_func[i](params, env);
        }
    }
    return -1;
}
