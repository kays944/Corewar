/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** exec_live
*/

#include <unistd.h>
#include <stdlib.h>
#include "instr.h"
#include "utils.h"

void exec_live(core_t *c, process_t *proc)
{
    char *nb = my_itoa(proc->champion->number);

    my_putstr("The player ", STDOUT_FILENO);
    my_putstr(nb, STDOUT_FILENO);
    my_putstr("(", STDOUT_FILENO);
    my_putstr(proc->champion->header.prog_name, STDOUT_FILENO);
    my_putstr(" )is alive.\n", STDOUT_FILENO);
    free(nb);
    proc->pc = (proc->pc + 5) % MEM_SIZE;
    (void)c;
}
