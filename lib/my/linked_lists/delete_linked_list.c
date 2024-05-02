/*
** EPITECH PROJECT, 2024
** Minishell_2
** File description:
** delete_linked_list
*/

#include "../lib_includes/linked_list.h"
#include <stdlib.h>

void delete_all_elements_in_list(linked_list_t **list,
    void (*free_function)(void *values))
{
    linked_list_t *element = *list;
    linked_list_t *next;

    while (element->value) {
        next = element->next;
        remove_from_list(list, element, free_function);
        element = next;
    }
    free(element);
    free(list);
}

int delete_linked_list(linked_list_t **list,
    void (*free_function)(void *values))
{
    linked_list_t *element;

    if (!list || !free_function) {
        return -1;
    }
    element = *list;
    if (!element) {
        free(list);
        return 0;
    }
    if (!element->value) {
        free(element);
        free(list);
        return 0;
    }
    delete_all_elements_in_list(list, free_function);
    return 0;
}
