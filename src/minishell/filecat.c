/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** filecat
*/

#include <stddef.h>

#include "my.h"
#include "minishell.h"

char *filecat(char *filepath, char *filename)
{
    int index = 0;
    int size = my_strlen(filepath) + my_strlen(filename);
    char *dest = my_memset(sizeof(char) * (size + 2), NULL);

    for (int i = 0; filepath[i] != '\0'; i++)
        dest[index++] = filepath[i];
    if ((index >= 1) && (dest[index - 1] != '/'))
        dest[index++] = '/';
    for (int i = 0; filename[i] != '\0'; i++)
        dest[index++] = filename[i];
    while (index < size)
        dest[index++] = '\0';
    return dest;
}
