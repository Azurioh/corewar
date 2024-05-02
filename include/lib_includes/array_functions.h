/*
** EPITECH PROJECT, 2024
** my_lib_c
** File description:
** array_functions
*/

#ifndef ARRAY_FUNCTIONS_H_
    #define ARRAY_FUNCTIONS_H_

/*!
** @brief Function to free an array with this content
** @param nb_arrays The number of array you want to free
** @param ... All the arrays you want to free
*/
void free_arrays(int nb_arrays, ...);

/*!
** @brief Function to insert a value in an array
** @param array The initial array where you want to add a value
** @param str The string you want to add on array
** @param index The index for the new value (-1 for the end)
** @return Return a new array
*/
char **insert_in_array(char **array, char *str, int index);

/*!
** @brief Function to get the len of an array
** @param array The array you want to know the len
** @return The size of the array
*/
int my_arraylen(char **array);

/*!
** @brief Function to remove a value in an array
** @param array The initial array where you want to remove a value
** @param index The index for the removed value (-1 for the end)
** @return Return a new array
*/
char **remove_in_array(char **array, int index);

/*!
** @brief Function to copy an array in another malloc
** @param array The initial array that you want to copy
** @return Return a new array
*/
char **my_arraydup(char **array);

#endif /* !ARRAY_FUNCTIONS_H_ */
