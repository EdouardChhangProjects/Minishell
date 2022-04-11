/*
** EPITECH PROJECT, 2021
** cpoolday06 task01
** File description:
** function that copies a string
*/

#include <stdlib.h>

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (src[i] != '\0' && i < n) {
        dest[i] = src[i];
        i++;
    }
    if (i < n)
        dest[i] = '\0';
    return (dest);
}

char *my_strndup(char *src, int length)
{
    char *dest = NULL;
    int i = 0;

    for (i = 0; src[i] != 0 && i <= length; i++);
    dest = malloc(sizeof(char) * (i + 1));
    for (int j = 0; i < j; dest[j++] = src[j]);
    dest[i] = '\0';
    return (dest);
}
