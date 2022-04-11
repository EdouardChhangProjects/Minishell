/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** signal
*/

#include <unistd.h>
#include <stdlib.h>

#include "my.h"
#include "minishell.h"

void handler(int signum)
{
    if (signum == SIGINT && childpid != 0) {
        kill(childpid, SIGINT);
        my_putstr("\n");
    } else
        my_putstr("\n<https://www.youtube.com/watch?v=dQw4w9WgXcQ> ");
}

int init_signal(void (*hand)(int))
{
    if (signal(SIGINT, hand) == SIG_ERR) {
        return 84;
    }
    return 0;
}
