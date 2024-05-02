/*
** EPITECH PROJECT, 2024
** Minishell_2
** File description:
** linked_list
*/

#ifndef LINKED_LIST_H_
    #define LINKED_LIST_H_
typedef struct linked_list_s {
    void *value;
    struct linked_list_s *next;
    struct linked_list_s *previous;
} linked_list_t;

/*!
** @brief Function to create an empty element
** @return Return an empty element of linked list
*/
linked_list_t *create_empty_element(void);

/*!
** @brief Function to a linked list
** @return Return a linked list
*/
linked_list_t **create_linked_list(void);

/*!
** @brief Function to add an element in a linked list
** @param list The linked list where you want to add a value
** @param value The value that you want to add in the linked list
** @return Return 0 if the value is added, otherwise -1
*/
int add_in_linked_list(linked_list_t **list, void *value);

/*!
** @brief Function to remove an element in a linked list
** @param list The linked list where you want to remove a value
** @param wanted The string you want to find in the linked list
** @param compare_function The function used to check every element of
linked list
** @param free_function The function used to free the linked list element
** @return Return 0 if the value is removed, otherwise -1
*/
int remove_in_linked_list(linked_list_t **list, char *wanted,
    int (*compare_function)(void *values, char *wanted),
    void (*free_function)(void *values));

/*!
** @brief Function to remove an element in a linked list
** @param list The linked list where you want to remove a value
** @param wanted The string you want to find in the linked list
** @param free_function The function used to free the linked list element
** @return Return 0 if the value is removed, otherwise -1
*/
void remove_from_list(linked_list_t **list, linked_list_t *element,
    void (*free_function)(void *values));

/*!
** @brief Function to delete & free a linked list
** @param list The linked list that you want to delete
** @param free_function The function used to free the linked list element
** @return Return a linked list
*/
int delete_linked_list(linked_list_t **list,
    void (*free_function)(void *values));

/*!
** @brief Function to display the content of a linked list
** @param list The linked list that you want to display
** @param separator A string that will be displayed after one element of
the linked list
** @param display_function A function used to display the content of the
linked list
** @param return_to_the_line A integer to print a "\n" at the end (0: no
| 1: yes)
** @return Return a linked list
*/
void display_linked_list(linked_list_t **list, char *separator,
    void (*display_function)(void *values),
    int return_to_the_line);

/*!
** @brief Function to search a value in linked_list
** @param list The linked list where you want to search an element
** @param wanted The string you want to find in the linked list
** @param compare_function The function used to check every element of
linked list
** @return Return the element found, otherwise NULL
*/
linked_list_t *search_in_linked_list(linked_list_t **list,
    char *wanted,
    int (*compare_function)(void *values, char *wanted));

/*!
** @brief Function to get the size of a linked list
** @param list The linked list that you want to know the size
** @return Return the size of the list
*/
int get_size_of_linked_list(linked_list_t **list);
#endif /* !LINKED_LIST_H_ */
