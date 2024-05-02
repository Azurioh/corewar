/*
** EPITECH PROJECT, 2024
** Project
** File description:
** get_number_of_occurences
*/

int get_number_of_occurences(char const *str, char character)
{
    int cpt = 0;

    if (!str) {
        return 0;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == character) {
            cpt++;
        }
    }
    return cpt;
}
