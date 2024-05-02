/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** printf function
*/

#include "../lib_includes/my_printf.h"
#include "../lib_includes/str_functions.h"
#include "../lib_includes/writing_functions.h"
#include "my_printf_var.h"
#include <stdlib.h>

static void reset_flag_indicator(void)
{
    flag_indicator.hashtag = 0;
    flag_indicator.zero = 0;
    flag_indicator.dash = 0;
    flag_indicator.space = 0;
    flag_indicator.plus = 0;
}

static void update_flag_indicator(char flag)
{
    if (flag == '#')
        flag_indicator.hashtag = 1;
    if (flag == '0' && flag_indicator.dash != 1)
        flag_indicator.zero = 1;
    if (flag == '-') {
        flag_indicator.dash = 1;
        flag_indicator.zero = 0;
    }
    if (flag == ' ' && flag_indicator.plus != 1)
        flag_indicator.space = 1;
    if (flag == '+') {
        flag_indicator.plus = 1;
        flag_indicator.space = 0;
    }
}

static int detect_prec(char const *str, int *index)
{
    int prec = 0;

    *index += 1;
    if (str[*index] < '0' || str[*index] > '9')
        return -1;
    while (str[*index] >= '0' && str[*index] <= '9') {
        prec = (prec * 10 + str[*index] - 48);
        *index += 1;
    }
    return prec;
}

static void detect_flag(int *index, char const *str)
{
    char *flag_array;

    flag_array = my_strdup("#0- +");
    for (int i = 0; flag_array[i] != '\0'; i++) {
        if (str[*index] == flag_array[i]) {
            update_flag_indicator(str[*index]);
            *index += 1;
            i = -1;
        }
    }
    free(flag_array);
}

int display_flag_entered(void)
{
    int nb = 0;

    if (flag_indicator.hashtag == 1)
        my_putchar('#');
    if (flag_indicator.plus == 1)
        my_putchar('+');
    if (flag_indicator.space == 1)
        my_putchar(' ');
    if (flag_indicator.zero == 1)
        my_putchar(' ');
    if (flag_indicator.dash == 1)
        my_putchar('-');
    nb += flag_indicator.hashtag + flag_indicator.plus;
    nb += flag_indicator.space + flag_indicator.zero;
    nb += flag_indicator.dash;
    return nb;
}

static void display_no_flag(int *index, char const *str, int *cpt)
{
    int actual_index = *index;

    while (str[*index] != '%' && includes_in_str("#0- +", str[*index]) == 0) {
        *index -= 1;
    }
    my_putchar('%');
    *index += 1;
    *cpt += display_flag_entered() + 1;
    while (*index != actual_index) {
        my_putchar(str[*index]);
        *cpt += 1;
        *index += 1;
    }
    my_putchar(str[*index]);
    *cpt += 1;
}

void display_flag(char const *str, int *index, va_list *list, int *cpt)
{
    int prec = -1;
    int printed = 0;

    detect_flag(index, str);
    if (str[*index] == '.') {
        prec = detect_prec(str, index);
    }
    for (int i = 0; CONVERSIONS[i].flag != 0; i++) {
        if (str[*index] == CONVERSIONS[i].flag) {
            *cpt += CONVERSIONS[i].function(list, prec, &flag_indicator, cpt);
            printed = 1;
        }
    }
    if (printed == 0) {
        display_no_flag(index, str, cpt);
    }
    reset_flag_indicator();
}

int my_printf(const char *format, ...)
{
    va_list list;
    int cpt = 0;

    va_start(list, format);
    reset_flag_indicator();
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            display_flag(format, &i, &list, &cpt);
        } else {
            my_putchar(format[i]);
            cpt++;
        }
    }
    va_end(list);
    return cpt;
}
