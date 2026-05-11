/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** read_champions.c
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "struct.h"
#include "macros.h"
#include "utils.h"
#include "op.h"
#include "corewar.h"

static int swap_endian(int value)
{
    int byte = ((value >> 24) & 0xFF)
        | ((value >> 8) & 0xFF00)
        | ((value << 8) & 0xFF0000)
        | ((value << 24) & 0xFF000000);

    return byte;
}

static int check_exec_magic(int fd, header_t *hd)
{
    if (read(fd, hd, sizeof(header_t)) == READ_ERROR)
        return EXIT_FAIL;
    hd->prog_size = swap_endian(hd->prog_size);
    hd->magic = swap_endian(hd->magic);
    if (hd->magic != COREWAR_EXEC_MAGIC) {
        my_putstr("error file invalid (different magic number)\n",
            STDERR_FILENO);
        return EXIT_FAIL;
    }
    return EXIT_SUCCESS;
}

static int get_bytecode(int fd, param_ch_t *ch)
{
    ch->bytecode = malloc(ch->header.prog_size * sizeof(char));
    if (!ch->bytecode)
        return EXIT_FAIL;
    if (read(fd, ch->bytecode, ch->header.prog_size) == READ_ERROR)
        return EXIT_FAIL;
    return EXIT_SUCCESS;
}

static int get_number(param_ch_t *ch, size_t nbr)
{
    if (ch->number == -1)
        ch->number = nbr;
    return EXIT_SUCCESS;
}

static int open_champions(param_ch_t *ch, size_t nbr, int nb_champions)
{
    int fd = open(ch->name, O_RDONLY);

    if (fd == OPEN_ERROR) {
        my_putstr("error: read: ", STDERR_FILENO);
        my_putstr(ch->name, STDERR_FILENO);
    }
    if (check_exec_magic(fd, &ch->header) == EXIT_FAIL
        || get_bytecode(fd, ch) == EXIT_FAIL
        || get_number(ch, nbr) == EXIT_FAIL)
        return EXIT_FAIL;
    return EXIT_SUCCESS;
}

int read_champions(core_t *opt)
{
    param_ch_t *head = opt->champions;
    size_t nbr = 0;

    while (head) {
        if (open_champions(head, nbr, opt->nb_champions) == EXIT_FAIL)
            return EXIT_FAIL;
        head = head->next;
        ++nbr;
    }
    init_memory(opt);
    return EXIT_SUCCESS;
}
