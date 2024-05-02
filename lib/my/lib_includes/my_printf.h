/*
** EPITECH PROJECT, 2024
** my_lib_c
** File description:
** my_printf
*/

#ifndef MY_PRINTF_H_
    #define MY_PRINTF_H_
    #include <stdarg.h>

typedef struct detect_flag_s {
    int hashtag;
    int zero;
    int dash;
    int space;
    int plus;
} detect_flag_t;

typedef struct conversions_s {
    char flag;
    int (*function)(va_list *, int, detect_flag_t *, int *);
} conversions_t;

/*!
** @brief Function to display some characters and some variables on
the terminal
** @param format The string that you want to display
** @param ... The variable you want to print
** @return Return the size of character printed
*/
int my_printf(const char *format, ...);

void get_int_flag(detect_flag_t *flag, int *nb_char, double value);
double get_double_entire(double nb);
int display_percentage(va_list *l, int p, detect_flag_t *f, int *c);
int display_int(va_list *l, int p, detect_flag_t *f, int *c);
int display_string(va_list *l, int p, detect_flag_t *f, int *c);
int display_char(va_list *l, int p, detect_flag_t *f, int *c);
int display_double(va_list *l, int p, detect_flag_t *f, int *c);
int display_hexa_min(va_list *l, int p, detect_flag_t *f, int *c);
int display_hexa_maj(va_list *l, int p, detect_flag_t *f, int *c);
int display_octal(va_list *l, int p, detect_flag_t *f, int *c);
int display_int_unsigned(va_list *l, int p, detect_flag_t *f, int *c);
int display_nb_char_show(va_list *l, int p, detect_flag_t *f, int *c);
int display_pointer(va_list *l, int p, detect_flag_t *f, int *c);
int display_errno(va_list *l, int p, detect_flag_t *f, int *c);
#endif /* !MY_PRINTF_H_ */
