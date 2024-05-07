/*
** EPITECH PROJECT, 2024
** is_file_exist
** File description:
** check if the file given as parameter exist
*/
#include <unistd.h>
#include <fcntl.h>

int is_file_exist(char *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd == -1)
        return 1;
    close(fd);
    return 0;
}
