/*
** EPITECH PROJECT, 2024
** Minishell_2
** File description:
** create_linked_list
*/

#include "../lib_includes/linked_list.h"
#include <stddef.h>
#include <stdlib.h>

linked_list_t *create_empty_element(void)
{
    linked_list_t *empty_element = malloc(sizeof(linked_list_t));

    empty_element->value = NULL;
    empty_element->next = NULL;
    empty_element->previous = NULL;
    return empty_element;
}

linked_list_t **create_linked_list(void)
{
    linked_list_t **linked_list = malloc(sizeof(linked_list_t *));
    linked_list_t *empty_element = create_empty_element();

    *linked_list = empty_element;
    return linked_list;
}
