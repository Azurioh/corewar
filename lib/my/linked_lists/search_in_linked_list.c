/*
** EPITECH PROJECT, 2024
** Minishell_2
** File description:
** delete_linked_list
*/

#include "../lib_includes/linked_list.h"
#include <stddef.h>

linked_list_t *search_in_linked_list(linked_list_t **list,
    char *wanted,
    int (*compare_function)(void *values, char *wanted))
{
    linked_list_t *element;

    if (!list || !wanted || !compare_function) {
        return NULL;
    }
    element = *list;
    if (!element) {
        return NULL;
    }
    while (element->value) {
        if (compare_function(element->value, wanted) == 0) {
            return element;
        } else {
            element = element->next;
        }
    }
    return NULL;
}
