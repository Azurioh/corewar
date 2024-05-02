/*
** EPITECH PROJECT, 2024
** Project
** File description:
** get_size_of_linked_list
*/

#include "../lib_includes/linked_list.h"

int get_size_of_linked_list(linked_list_t **list)
{
    linked_list_t *step;
    int size = 0;

    if (!list) {
        return 0;
    }
    step = *list;
    if (!step) {
        return 0;
    }
    while (step->value) {
        size++;
        step = step->next;
    }
    return size;
}
