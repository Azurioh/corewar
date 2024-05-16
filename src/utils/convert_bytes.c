/*
** EPITECH PROJECT, 2024
** convert_bytes
** File description:
** Function to bitshift memory element
*/

#include "../../include/corewar.h"

static void convert_decimal_to_hexa(int nb, int *result)
{
    int calcul = nb;
    int tmp;
    int j = 3;
    static int increment = 0;

    while (calcul != 0) {
        tmp = calcul % 16;
        if (increment == 1) {
            result[j] += tmp << 4;
            j--;
        } else {
            increment++;
            result[j] += tmp;
        }
        calcul /= 16;
    }
    return;
}

int convert_4bytes(unsigned char *memory, int index)
{
    int bitshift = 0;
    int value;

    for (int i = 0; i < 4; i++) {
        value = get_address_value(memory, index + (i + 1));
        bitshift += value << (8 * (3 - i));
    }
    return bitshift;
}

int convert_xbytes(unsigned char *memory, int index, int nb_read)
{
    int bitshift = 0;
    int value;

    for (int i = 0; i < nb_read; i++) {
        value = get_address_value(memory, index + (i + 1));
        bitshift += value << (8 * ((nb_read - 1) - i));
    }
    return bitshift;
}

int *convert_to_4bytes(int bitshift)
{
    int *value = malloc(sizeof(char) * 4);

    for (int i = 0; i < 4; i++) {
        value[i] = 0;
    }
    convert_decimal_to_hexa(bitshift, value);
    return value;
}

int convert_2bytes(unsigned char *memory, int index)
{
    int bitshift = 0;

    bitshift += get_address_value(memory, index + 1) << (4 * 2);
    bitshift += get_address_value(memory, index + 2);
    return bitshift;
}
