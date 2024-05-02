/*
** EPITECH PROJECT, 2024
** my_lib_c
** File description:
** utils_functions
*/

#ifndef UTILS_FUNCTIONS_H_
    #define UTILS_FUNCTIONS_H_

/*!
** @brief Function that give the number of digit in an integer
** @param nb The integer that you want the size
** @return The number of digit in the integer
*/
int my_int_len(int nb);

/*!
** @brief Function that do the pow operation
** @param nb The number
** @param p The power
** @return Return the result of nb^p
*/
int my_pow(int nb, int p);

/*!
** @brief Function that give the number of digit in an unsigned int
** @param nb The unsigned int that you want the size
** @return The number of digit in the unsigned int
*/
int my_uns_int_len(unsigned int nb);
#endif /* !UTILS_FUNCTIONS_H_ */
