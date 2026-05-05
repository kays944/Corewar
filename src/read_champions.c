/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** read_champions.c
*/

#include "struct.h"
#include "macros.h"
#include "utils.h"
#include "op.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int swap_endian(int value)
{
    int byte = ((value >> 24) & 0xFF)
        | ((value >> 8) & 0xFF00)
        | ((value << 8) & 0xFF0000)
        | ((value << 24) & 0xFF000000);

    return byte;
}

int check_exec_magic(int fd, header_t *hd)
{
    if (read(fd, &hd, sizeof(header_t)) == READ_ERROR)
        return EXIT_FAIL;
    if (swap_endian(hd->magic) != COREWAR_EXEC_MAGIC) {
        printf("error file invalid (different magic number)\n");
        return EXIT_FAIL;
    }
    return EXIT_SUCCESS;
}

int get_bytecode(int fd, param_ch_t *ch)
{
    ch->bytecode = malloc(ch->header.prog_size * sizeof(char));
    if (!ch->bytecode)
        return EXIT_FAIL;
    if (read(fd, &ch->bytecode, ch->header.prog_size) == READ_ERROR)
        return EXIT_FAIL;
    return EXIT_SUCCESS;
}

int open_champions(char *path, param_ch_t *ch)
{
    int fd = open(path, O_RDONLY);

    if (fd == OPEN_ERROR) {
        my_putstr("error: read: ", STDERR_FILENO);
        my_putstr(path, STDERR_FILENO);
    }
    if (check_exec_magic(fd, &ch->header) == EXIT_FAIL)
        return EXIT_FAIL;
    if (get_bytecode(fd, ch) == EXIT_FAIL)
        return EXIT_FAIL;
    return EXIT_SUCCESS;
}

int read_champions(option_t *opt)
{
    param_ch_t *head = opt->champions;

    while (head) {
        printf("ch : %s\n", head->name);
        open_champions(head->name, head);
        head = head->next;
    }
    return EXIT_SUCCESS;
}
