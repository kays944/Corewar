/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** exec_live
*/

#include <stdio.h>

#include <unistd.h>
#include <stdlib.h>
#include "instr.h"
#include "utils.h"

void exec_live(core_t *c, process_t *proc)
{
    my_putstr("live: cycle: ", STDOUT_FILENO);
    my_putnbr(c->cycle, STDOUT_FILENO);
    my_putstr(" The player ", STDOUT_FILENO);
    my_putstr(proc->champion->header.prog_name, STDOUT_FILENO);
    my_putstr(" (", STDOUT_FILENO);
    my_putnbr(proc->champion->number, STDOUT_FILENO);
    my_putstr(") is alive.\n", STDOUT_FILENO);
    proc->pc = (proc->pc + 5) % MEM_SIZE;
    proc->next_execution = 10;
    proc->last_live = c->cycle;
    ++c->live_count;
    if (c->live_count == NBR_LIVE) {
        c->cycle_to_die -= CYCLE_DELTA;
        c->live_count = 0;
    }
}
