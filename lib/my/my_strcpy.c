/*
** EPITECH PROJECT, 2021
** cpoolday06 task01
** File description:
** function that copies a string
*/

#include <stdlib.h>

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *my_strdup(char *src)
{
    char *dest = NULL;
    int i = 0;

    for (i = 0; src[i] != '\0'; i++);
    dest = malloc(sizeof(char) * (i + 1));
    for (i = 0; src[i] != '\0'; dest[i++] = src[i]);
    dest[i] = '\0';
    return (dest);
}
