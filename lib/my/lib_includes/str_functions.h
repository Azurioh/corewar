/*
** EPITECH PROJECT, 2024
** my_lib_c
** File description:
** str_functions
*/

#ifndef STR_FUNCTIONS_H_
    #define STR_FUNCTIONS_H_

/*!
** @brief Function to add a character in a string
** @param dest The string where you want to add a character
** @param new_char The character that you want to add
*/
void append(char *dest, char new_char);

/*!
** @brief Function to add a character in a string
** @param str The string where you want to add a character
** @param character The character that you want to add
** @param index The index where the character must be placed
(-1 for the end of the string)
** @return Return a new string
*/
char *add_char_in_str(char *str, char character, int index);

/*!
** @brief Function to check if a character is on a string
** @param str The string that you want to check
** @param to_find The character that you want to know if is on the string
** @return Return 1 if the character is on the string, otherwise 0
*/
int includes_in_str(char const *str, char to_find);

/*!
** @brief Function to create a string with 2 others
** @param s1 The first string
** @param s2 The second string
** @return Return a string that include first and second string
*/
char *my_strcat(char *s1, char const *s2);

/*!
** @brief Function to check if two strings are same
** @param s1 The first string
** @param s2 The second string
** @return Return 0 if the both strings are same, otherwise
the function return the difference between s1 and s2
*/
int my_strcmp(char *s1, char *s2);

/*!
** @brief Function to duplicate the string with a new malloc
** @param str The str that will be copied
** @return The new str
*/
char *my_strdup(char const *str);

/*!
** @brief Function to get the size of a string
** @param str The str that you want to get the size
** @return The size of the string
*/
int my_strlen(char const *str);

/*!
** @brief Function to check if two strings are same with a limit
** @param s1 The first string
** @param s2 The second string
** @param index The end index when to stop to compare the strings
** @return Return 0 if the both strings are same, otherwise the function
return the difference between s1 and s2
*/
int my_strncmp(char *s1, char *s2, int limit);

/*!
** @brief Function to copy a string into another with a limit
** @param dest The string where content will be copied
** @param src The string where content will be extracted
** @param n The limit of copy
** @return Return the new string
*/
char *my_strncpy(char *dest, char const *src, int n);

/*!
** @brief Function to check if the string is a number
** @param str The string that you want to check
** @return Return 0 if the string is a number, otherwise -1
*/
int str_is_nb(char const *str);

/*!
** @brief Function to get the number of occurences of a letter in a string
** @param str The string that you want
** @param character The character you want to find
** @return Return the number of occurences of `letter`
*/
int get_number_of_occurences(char const *str, char character);

/*!
** @brief Function to remove a char in a string
** @param str The string that you want remove a character
** @param index The index where you want to remove the character
** @return Return a new string
*/
char *remove_char_in_str(char *str, int index);
char *my_strndup(char *str, int n);
#endif /* !STR_FUNCTIONS_H_ */
