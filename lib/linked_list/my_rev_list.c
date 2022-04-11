/*
** EPITECH PROJECT, 2021
** libmyll.a
** File description:
** rev linked list
*/

#include "my_linked_list.h"
#include <stddef.h>

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *previous = NULL;
    int len = my_list_size(*begin);
    linked_list_t *tmp;
    linked_list_t *current = *begin;

    for (int i = 0 ; i <= len; i++) {
        tmp = previous;
        previous = current;
        current = current->next;
        previous->next = tmp;
    }
    *begin = previous;
}
