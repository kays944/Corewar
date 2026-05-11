/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** helper.c
*/

#include <unistd.h>
#include "utils.h"
#include "macros.h"

int helper(void)
{
    my_putstr("USAGE\n", STDOUT_FILENO);
    my_putstr("./corewar [-dump nbr_cycle] [[-n prog_number] [-a load_address]"
        " prog_name] ...", STDOUT_FILENO);
    my_putstr("DESCRIPTION\n", STDOUT_FILENO);
    my_putstr("-dump nbr_cycle dumps the state of the virtual machine after"
        " the nbr_cycle execution\n", STDOUT_FILENO);
    my_putstr("-n prog_number sets the next program’s number. By default, the"
        " first free number in the parameter\norder\n", STDOUT_FILENO);
    my_putstr("-a load_address sets the next program’s loading address. When"
        " no address is specified, optimize the\n", STDOUT_FILENO);
    my_putstr("addresses so that the processes are as far away from each other"
        " as possible. The addresses are\n", STDOUT_FILENO);
    my_putstr("MEM_SIZE modulo.\n", STDOUT_FILENO);
    return EXIT_SUCCESS;
}
