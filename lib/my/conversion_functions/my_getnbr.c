/*
** EPITECH PROJECT, 2024
** my_lib_c
** File description:
** my_getnbr
*/

int detect_first_number(char const *str)
{
    int index = 0;

    if (!str) {
        return -1;
    }
    while (str[index] != '\0') {
        if (str[index] >= '1' && str[index] <= '9') {
            return index;
        }
        if (str[index] == '0' || str[index] == '-') {
            index++;
        } else {
            return -1;
        }
    }
    return -1;
}

int detect_last_number(char const *str, int index)
{
    while (str[index] >= '0' && str[index] <= '9') {
        index++;
    }
    return index - 1;
}

int get_symbol(char const *str, int index)
{
    int new_index = 0;
    int number_of_dash = 0;

    while (new_index != index) {
        if (str[new_index] == '-') {
            number_of_dash++;
        }
        new_index++;
    }
    if (number_of_dash % 2 == 0) {
        return 1;
    } else {
        return -1;
    }
}

int str_to_int(char const *str, int start_index, int end_index)
{
    int number = 0;

    number += str[start_index] - 48;
    start_index++;
    while (start_index != end_index + 1) {
        number = number * 10 + (str[start_index] - 48);
        start_index++;
    }
    if (number < 0) {
        return 0;
    } else {
        return number;
    }
}

int my_getnbr(char const *str)
{
    int start_index = detect_first_number(str);
    int end_index;
    int number = 0;

    if (start_index != -1) {
        end_index = detect_last_number(str, start_index);
        if (end_index - start_index > 10) {
            return 0;
        }
        number = str_to_int(str, start_index, end_index);
        number *= get_symbol(str, start_index);
        return number;
    } else {
        return 0;
    }
}
