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

static int check_live(process_t *proc, core_t *c)
{
    int count_proc_live = 0;

    while (proc) {
        if (c->cycle - proc->last_live <= c->cycle_to_die)
            ++count_proc_live;
        proc = proc->next;
    }
    return count_proc_live;
}

static int who_last_live(process_t *proc, size_t cycle)
{
    process_t *winner = NULL;

    while (proc) {
        if (cycle - proc->last_live <= CYCLE_TO_DIE) {
            winner = proc;
            break;
        }
        proc = proc->next;
    }
    if (!winner)
        return EXIT_FAIL;
    my_putstr("Victoire de ", STDOUT_FILENO);
    my_putstr(winner->champion->header.prog_name, STDOUT_FILENO);
    my_putstr("\n", STDOUT_FILENO);
    return EXIT_SUCCESS;
}

int main_loop(core_t *c)
{
    c->cycle = 0;
    c->live_count = 0;
    c->cycle_to_die = CYCLE_TO_DIE;
    while (check_live(c->proc, c) > 1) {
        if (c->cycle == 1000001)
            return EXIT_FAIL;
        if (c->nbr_cycle > 0 && c->cycle % c->nbr_cycle == 0)
            dump(c);
        if (execution_cycle(c) == EXIT_FAIL)
            return EXIT_FAIL;
        ++c->cycle;
    }
    who_last_live(c->proc, c->cycle);
    return EXIT_SUCCESS;
}
