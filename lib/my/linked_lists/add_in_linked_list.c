/*
** EPITECH PROJECT, 2024
** Minishell_2
** File description:
** add_in_linked_list
*/

#include "../lib_includes/linked_list.h"
#include "../lib_includes/writing_functions.h"
#include <stddef.h>
#include <stdlib.h>

int add_in_list(linked_list_t **list, linked_list_t *new_element)
{
    linked_list_t *first_element = *list;

    if (!first_element) {
        return -1;
    }
    new_element->next = first_element;
    if (first_element->value != NULL) {
        new_element->previous = first_element->previous;
    } else {
        new_element->previous = create_empty_element();
    }
    first_element->previous = new_element;
    *list = new_element;
    return 0;
}

int add_in_linked_list(linked_list_t **list, void *value)
{
    linked_list_t *new_element = malloc(sizeof(linked_list_t));

    if (!new_element) {
        my_puterr("add_in_linked_list: Memory allocation failed\n");
        return -1;
    }
    if (!list || !value) {
        return -1;
    }
    new_element->value = value;
    return add_in_list(list, new_element);
}
