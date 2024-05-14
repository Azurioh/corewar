/*
** EPITECH PROJECT, 2024
** read_file
** File description:
** return a buffer from the file gicen as parameter
*/

#include "../../include/corewar.h"

int read_file(char *filepath, unsigned char **buff)
{
    struct stat s;
    int fd;
    size_t size;

    fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        my_printf("Can't open %s\n", filepath);
        free(*buff);
        return fd;
    }
    stat(filepath, &s);
    *buff = malloc(s.st_size + 1);
    size = read(fd, *buff, s.st_size);
    (*buff)[size] = '\0';
    close(fd);
    return (int)size;
}
