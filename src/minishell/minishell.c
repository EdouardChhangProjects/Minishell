/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** minishell
*/

#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

#include "my.h"
#include "minishell.h"
#include "my_linked_list.h"

volatile sig_atomic_t childpid = 0;

int my_execve(char *path, char **argv, linked_list_t *env, int ret)
{
    int pid = 0;
    int *stat_loc = my_memset(sizeof(int *), NULL);
    char **char_env = list_to_array(env);

    if ((pid = fork()) == 0) {
        execve(path, argv, char_env);
        exit(84);
    }
    childpid = pid;
    ret = waitpid(pid, stat_loc, 0);
    childpid = 0;
    if (WIFEXITED(*stat_loc))
        if (WEXITSTATUS(*stat_loc) == 84)
            return 84;
    if (WIFSIGNALED(*stat_loc))
        my_printf("%s\n", strsignal(WTERMSIG(*stat_loc)));
    return ret;
}

int check_error(char *path, char **params)
{
    if (path == NULL) {
        my_put_error(*params);
        return my_put_error(": Command not found.\n");
    }
    if (is_exec(path) == 0) {
        my_put_error(path);
        my_put_error(": Permission denied.\n");
        return 84;
    }
    return 0;
}

int execute(char *str, linked_list_t **env, int ret)
{
    char **params = NULL;
    char *path = NULL;

    if (str[0] == '\n')
        return 0;
    params = get_params(str);
    path = format_params(params, *env);
    if ((ret = check_builtin(params[0], params, env)) != -1)
        return ret;
    if (check_error(path, params) == 84) {
        ret = 1;
        free_array((void **)params);
        free(path);
        return ret;
    }
    ret = my_execve(path, params, *env, ret);
    free_array((void **)params);
    free(path);
    return ret;
}

int minishell(char **env)
{
    char *str = NULL;
    size_t len = 0;
    long int end = 0;
    linked_list_t *my_env = my_params_to_list(my_arrlen((void **)env), env);
    int ret = 0;

    if (init_signal(handler) == 84)
        return 84;
    while (end >= 0) {
        if (isatty(0))
            my_putstr("<https://www.youtube.com/watch?v=dQw4w9WgXcQ> ");
        end = getline(&str, &len, stdin);
        if (my_strcmp("exit\n", str) == 0)
            end = -1;
        if (end != -1)
            ret = execute(str, &my_env, ret);
    }
    if (isatty(0))
        my_putstr("exit\n");
    return ret;
}
