/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** main_loop.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "utils.h"
#include "struct.h"
#include "macros.h"
#include "corewar.h"

static int check_live(process_t *proc, size_t cycle)
{
    int count_proc_live = 0;

    while (proc) {
        if (cycle - proc->last_live <= CYCLE_TO_DIE)
            ++count_proc_live;
        proc = proc->next;
    }
    return count_proc_live;
}

int main_loop(core_t *c)
{
    size_t cycle = 0;

    while (check_live(c->proc, cycle) > 0) {
        if (c->nbr_cycle > 0 && cycle % c->nbr_cycle == 0)
            dump(c, cycle);
        execution_cycle(c);
        ++cycle;
    }
    return EXIT_SUCCESS;
}
