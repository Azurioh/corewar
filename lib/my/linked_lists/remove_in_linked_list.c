/*
** EPITECH PROJECT, 2024
** Minishell_2
** File description:
** remove_in_linked_list
*/

#include "../lib_includes/linked_list.h"
#include <stddef.h>
#include <stdlib.h>

void remove_from_list(linked_list_t **list, linked_list_t *element,
    void (*free_function)(void *values))
{
    element->previous->next = element->next;
    element->next->previous = element->previous;
    if (*list == element) {
        *list = element->next;
        if ((*list)->value == NULL) {
            free((*list)->previous);
            (*list)->previous = NULL;
        }
    }
    free_function(element->value);
    free(element);
}

int remove_in_linked_list(linked_list_t **list, char *wanted,
    int (*compare_function)(void *values, char *wanted),
    void (*free_function)(void *values))
{
    linked_list_t *element;

    if (!list || !wanted || !compare_function || !free_function) {
        return -1;
    }
    element = *list;
    if (!element) {
        return -1;
    }
    while (element->value) {
        if (compare_function(element->value, wanted) == 0) {
            remove_from_list(list, element, free_function);
            return 0;
        } else {
            element = element->next;
        }
    }
    return -1;
}
