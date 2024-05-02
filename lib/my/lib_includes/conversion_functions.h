/*
** EPITECH PROJECT, 2024
** my_lib_c
** File description:
** conversion_functions
*/

#ifndef CONVERSION_FUNCTIONS_H_
    #define CONVERSION_FUNCTIONS_H_

/*!
** @brief Function to convert string to a integer
** @param str The string you want to convert to an integer
** @return Return the integer include in the string
*/
int my_getnbr(char const *str);

/*!
** @brief Function to convert a string to a word array
** @param str The string you want to convert
** @param step The string that includes some characters to separate the word
array
** @return Return a array
*/
char **my_str_to_word_array(char const *str, char const *step);

/*!
** @brief Function to convert an integer to a string
** @param nb The integer that you want to convert to a string
** @return Return the string
*/
char *my_nbr_to_str(int nb);

/*!
** @brief Function to convert a word array to a string
** @param array The array you want to convert
** @param separator The string you want to have between each word array
** @return Return a string
*/
char *my_word_array_to_str(char **word_array, char *separator);

#endif /* !CONVERSION_FUNCTIONS_H_ */
