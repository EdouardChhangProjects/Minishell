/*
** EPITECH PROJECT, 2021
** ex
** File description:
** ex header
*/

#ifndef MY_LIST_
    #define MY_LIST_

    typedef struct linked_list {
        void *data;
        struct linked_list *next;
    } linked_list_t;

    int my_list_size(linked_list_t const *begin);
    linked_list_t *my_params_to_list(int ac, char * const *av);
    void my_show_linked_list(linked_list_t *list);
    void my_rev_list(linked_list_t **begin);
    linked_list_t *first_node(void *data);
    int add_node(void *data, linked_list_t **list);
    int insert_node(void *data, linked_list_t *prev);
    int add_end_node(void *data, linked_list_t **list);
    char **list_to_array(linked_list_t *list);
	int delete_node(linked_list_t **prev);

#endif
