/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** free_array
*/

#include <stdlib.h>

int free_array(void **array)
{
    for (int i = 0; array[i] != NULL ; i++)
        free(array[i]);
    free(array);
}
