/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** list_to_array
*/

#include <stddef.h>

#include "my_linked_list.h"

void *my_memset(int len, char *str);
char *my_strdup(char *str);

char **list_to_array(linked_list_t *list)
{
    int len = my_list_size(list);
    char **dest = my_memset(sizeof(char *) * (len + 1), NULL);
    int i = 0;

    if (dest == NULL)
        return NULL;
    while (list != NULL) {
        dest[i++] = my_strdup((char *)(list->data));
        list = list->next;
    }
    dest[i] == NULL;
    return dest;
}
