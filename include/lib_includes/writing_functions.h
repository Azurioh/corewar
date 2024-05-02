/*
** EPITECH PROJECT, 2024
** my_lib_c
** File description:
** writing_functions
*/

#ifndef WRITING_FUNCTIONS_H_
    #define WRITING_FUNCTIONS_H_

/*!
** @brief Function that display one char on the standard output
** @param c The char wanted
*/
void my_putchar(char c);

/*!
** @brief Function that display a string on the error output
** @param str The string wanted
*/
void my_puterr(char const *str);

/*!
** @brief Function that display an unsigned int on the standard output
** @param nb The unsigned int wanted
*/
void my_putnbr_uns(unsigned int nb);

/*!
** @brief Function that display an integer on the standard output
** @param nb The integer wanted
*/
void my_putnbr(int nb);

/*!
** @brief Function that display a string on the standard output
** @param str The string wanted
*/
void my_putstr(char const *str);
#endif /* !WRITING_FUNCTIONS_H_ */
