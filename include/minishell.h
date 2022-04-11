/*
** EPITECH PROJECT, 2021
** ex
** File description:
** ex header
*/

#ifndef MINISHELL_H_
    #define MINISHELL_H_

    #include <signal.h>

    extern volatile sig_atomic_t childpid;

    typedef struct ll_env_s {
        char *name;
        char *value;
        struct ll_env_s *env;
    } ll_env_t;

    #include "my_linked_list.h"

    int minishell(char **env);
    char **get_params(char *str);
    char *filecat(char *filepath, char *filename);
    int is_exec(char *fp);
    char *format_params(char **params, linked_list_t *env);
    int init_signal(void (*hand)(int));
    void handler(int signum);
    int check_builtin(char *str, char **params, linked_list_t **env);
    int builtin_env(char **params, linked_list_t **env);
    int builtin_setenv(char **params, linked_list_t **env);
    int builtin_unsetenv(char **params, linked_list_t **env);
    int builtin_cd(char **params, linked_list_t **env);
    char **str_to_array(char *str, char sep);
    int is_all_alphanum(char *str);
    char *envcat(char *env, char *value);

#endif
