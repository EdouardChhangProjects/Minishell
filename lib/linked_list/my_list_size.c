/*
** EPITECH PROJECT, 2021
** libmy.a
** File description:
** linked list header
*/

#include "my_linked_list.h"
#include <stddef.h>

int my_list_size(linked_list_t const *begin)
{
    int size = 1;

    if (begin == NULL)
        return 0;
    while (begin->next != NULL) {
        size += 1;
        begin = begin->next;
    }
    return (size);
}
