/*
** EPITECH PROJECT, 2023
** conv_dec_hexa
** File description:
** convert an unsigned int into hexadecimal and display it
*/

#include "../lib_includes/my_printf.h"
#include "../lib_includes/str_functions.h"
#include "../lib_includes/writing_functions.h"

void conv_dec_hexa(unsigned int nb, int *nb_char, int maj, char *str)
{
    int rslt;

    if (nb == 0)
        return;
    else {
        rslt = nb % 16;
        if (rslt > 9 && maj == 0)
            rslt += 'a' - 58;
        if (rslt > 9 && maj == 1)
            rslt += 'A' - 58;
        conv_dec_hexa((nb / 16), nb_char, maj, str);
        *nb_char += 1;
        append(str, rslt + 48);
    }
}

int display_hexa_min(va_list *l, int p, detect_flag_t *f, int *c)
{
    unsigned int nb = va_arg(*l, unsigned int);
    int nb_char = 0;
    char *str = my_strdup("");

    c = c;
    if (nb == 0) {
        my_putchar('0');
        return nb_char + 1;
    }
    if (f->hashtag == 1) {
        my_putstr("0x");
        nb_char += 2;
    }
    conv_dec_hexa(nb, &nb_char, 0, str);
    for (int i = my_strlen(str); i < p; i++) {
        my_putchar('0');
        nb_char++;
    }
    my_putstr(str);
    return nb_char;
}

int display_hexa_maj(va_list *l, int p, detect_flag_t *f, int *c)
{
    unsigned int nb = va_arg(*l, unsigned int);
    int nb_char = 0;
    char *str = my_strdup("");

    c = c;
    if (nb == 0) {
        my_putchar('0');
        return nb_char + 1;
    }
    if (f->hashtag == 1) {
        my_putstr("0X");
        nb_char += 2;
    }
    conv_dec_hexa(nb, &nb_char, 1, str);
    for (int i = my_strlen(str); i < p; i++) {
        my_putchar('0');
        nb_char++;
    }
    my_putstr(str);
    return nb_char;
}
