/*
** EPITECH PROJECT, 2024
** read_coding_style
** File description:
** read the coding byte and return an array of the parameters type
*/
#include "../../include/corewar.h"

char *conv_binary(int nb)
{
    char *binary = malloc(sizeof(char) * 9);
    int i;

    for (i = 0; nb > 0; i++) {
        binary[i] = nb % 2 + 48;
        nb = nb / 2;
    }
    if (i < 8) {
        for (; i < 8; i++)
            binary[i] = '0';
    }
    binary[i] = '\0';
    my_revstr(binary);
    return binary;
}

int nb_parameters(char *binary)
{
    int len = 0;

    for (int i = 0; i != 8; i += 2) {
        if (binary[i] == '0' && binary[i + 1] == '0')
            break;
        len += 1;
    }
    return len;
}

char *read_coding_byte(int byte)
{
    char *binary_string = conv_binary(byte);
    char *parameters = NULL;
    int nb_params = 0;
    int i = 0;

    if (byte > 255)
        return NULL;
    nb_params = nb_parameters(binary_string);
    parameters = malloc(sizeof(char) * (nb_params + 1));
    for (i = 0; i < nb_params; i++) {
        if (binary_string[i * 2] == '0' && binary_string[i * 2 + 1] == '1')
            parameters[i] = T_REG;
        if (binary_string[i * 2] == '1' && binary_string[i * 2 + 1] == '0')
            parameters[i] = T_DIR;
        if (binary_string[i * 2] == '1' && binary_string[i * 2 + 1] == '1')
            parameters[i] = T_IND;
    }
    parameters[i] = '\0';
    free(binary_string);
    return parameters;
}
