/*
** EPITECH PROJECT, 2021
** libmy.a
** File description:
** puts params into linked list
*/

#include "my_linked_list.h"
#include <stdlib.h>

linked_list_t *my_params_to_list(int ac, char * const *av)
{
    linked_list_t *ptr = NULL;
    linked_list_t *prev = NULL;
    linked_list_t *cur_element = NULL;

    if (av == NULL)
        return (NULL);
    for (int i = 0; i < ac; i++) {
        ptr = cur_element;
        cur_element = malloc(sizeof(linked_list_t));
        if (cur_element == NULL)
            return (NULL);
        cur_element->data = av[i];
        cur_element->next = ptr;
    }
    return (cur_element);
}
