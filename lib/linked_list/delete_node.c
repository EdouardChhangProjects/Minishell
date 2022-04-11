/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** delete_node
*/

#include <stddef.h>
#include <stdlib.h>

#include "my_linked_list.h"

int delete_node(linked_list_t **prev)
{
    linked_list_t *buf = NULL;

    if (prev == NULL)
        return 84;
    if ((*prev) == NULL) {
        return 84;
    }
    if ((*prev)->next == NULL) {
        free(*prev);
        *prev = NULL;
        return 0;
    }
    buf = (*prev)->next;
    (*prev)->next = (*prev)->next->next;
    free(buf);
    return 0;
}
