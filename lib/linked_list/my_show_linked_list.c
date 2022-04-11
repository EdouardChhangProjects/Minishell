/*
** EPITECH PROJECT, 2021
** libmy.a function
** File description:
** shows content of a linked list
*/

#include <unistd.h>
#include "my_linked_list.h"

void my_putstr(char *str);

void my_show_linked_list(linked_list_t *list)
{
    while (list != NULL) {
        my_putstr((char *)list->data);
        write(1, "\n", 1);
        list = list->next;
    }
}
