/*
** EPITECH PROJECT, 2022
** linked_list
** File description:
** add_node
*/

#include <stddef.h>
#include <stdlib.h>

#include "my_linked_list.h"

int my_put_error(char *str);

linked_list_t *first_node(void *data)
{
    linked_list_t *dest = malloc(sizeof(linked_list_t));

    if (dest == NULL)
        return NULL;
    dest->next = NULL;
    dest->data = data;
    return dest;
}

int add_node(void *data, linked_list_t **list)
{
    linked_list_t *dest = NULL;

    if (list == NULL)
        return 84;
    if ((dest = malloc(sizeof(linked_list_t))) == NULL)
        return 84;
    dest->data = data;
    dest->next = (*list);
    (*list) = dest;
    return 0;
}

int insert_node(void *data, linked_list_t *prev)
{
    linked_list_t *dest = NULL;

    if (prev == NULL)
        return 84;
    if ((dest = malloc(sizeof(linked_list_t))) == NULL)
        return 84;
    dest->data = data;
    dest->next = prev->next;
    prev->next = dest;
    return 0;
}

int add_end_node(void *data, linked_list_t **list)
{
    linked_list_t *dest = NULL;
    linked_list_t *start = *list;

    if (list == NULL)
        my_put_error("add_end_node: NULL pointer passed\n");
    if ((*list) == NULL) {
        (*list) = first_node(data);
        return 0;
    }
    while ((*list)->next != NULL)
        (*list) = (*list)->next;
    if ((dest = malloc(sizeof(linked_list_t))) == NULL)
        return 84;
    dest->data = data;
    dest->next = NULL;
    (*list)->next = dest;
    (*list) = start;
    return 0;
}
