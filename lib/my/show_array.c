/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** show_array
*/

#include <stddef.h>

void my_putstr(char *str);

int show_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        my_putstr(array[i]);
        my_putstr("\n");
    }
    return 0;
}
