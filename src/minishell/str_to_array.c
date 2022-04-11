/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** str_to_array
*/

#include <stdlib.h>

#include "my.h"

int count_words(char *str, char sep)
{
    int nb_words = 0;
    int i = 0;

    while (str[i] != '\0') {
        while (str[i] == sep && str[i] != '\0')
            i++;
        if (str[i] != '\0')
            nb_words++;
        while (str[i] != sep && str[i] != '\0')
            i++;
        i++;
    }
    return nb_words;
}

char **dup_array(char *str, char **dest, int len_array, char sep)
{
    int len = 0;
    int index_array = 0;

    for (int i = 0; i < len_array; i++) {
        while ((str[index_array] == sep ||  str[index_array] == '\t') && \
str[index_array] != '\0')
            index_array++;
        len = 0;
        while ((str[index_array] != sep || str[index_array] == '\t') && \
str[index_array] != '\0') {
            index_array++;
            len++;
        }
        dest[i] = my_memset(sizeof(char) * (len + 1), NULL);
        my_strncpy(dest[i], &str[index_array - len], len);
    }
    return dest;
}

char **str_to_array(char *str, char sep)
{
    int nb_words = count_words(str, sep);
    char **dest = my_memset(sizeof(char *) * (nb_words + 1), NULL);

    return dup_array(str, dest, nb_words, sep);
}
