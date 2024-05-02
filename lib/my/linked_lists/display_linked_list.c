/*
** EPITECH PROJECT, 2024
** Minishell_2
** File description:
** display_linked_list
*/

#include "../lib_includes/linked_list.h"
#include "../lib_includes/my_printf.h"

void display_elements(linked_list_t *element, char *separator,
    void (*display_function)(void *values))
{
    if (!element || !element->value || !display_function) {
        return;
    }
    if (element->value) {
        display_elements(element->next, separator, display_function);
    }
    display_function(element->value);
    if (separator) {
        my_printf("%s", separator);
    }
}

void display_linked_list(linked_list_t **list, char *separator,
    void (*display_function)(void *values),
    int return_to_the_line)
{
    if (!list || !display_function) {
        return;
    }
    display_elements(*list, separator, display_function);
    if (return_to_the_line == 1) {
        my_printf("\n");
    }
}
