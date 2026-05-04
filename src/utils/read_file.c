/*
** EPITECH PROJECT, 2025
** robot_factory
** File description:
** read_file.c
*/

#include "utils.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

char *read_file(char *file)
{
    int fd = 0;
    char *buffer = NULL;
    int size = 0;
    struct stat s;

    if (stat(file, &s) != 0) {
        my_putstr("read: failure\n", STDERR_FILENO);
        return NULL;
    }
    fd = open(file, O_RDONLY);
    if (fd == -1) {
        my_putstr("read: failure\n", STDERR_FILENO);
        return NULL;
    }
    size = s.st_size;
    buffer = malloc((size + 1) * sizeof(char));
    read(fd, buffer, s.st_size);
    buffer[size] = '\0';
    close(fd);
    return buffer;
}
