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

static int end_equality(core_t *c)
{
    process_t *head = c->proc;

    my_putstr("\n\nCes champions : \n", STDOUT_FILENO);
    while (head) {
        if (c->cycle - head->last_live <= CYCLE_TO_DIE) {
            my_putstr("    - ", STDOUT_FILENO);
            my_putstr(head->champion->header.prog_name, STDOUT_FILENO);
            my_putstr(" (", STDOUT_FILENO);
            my_putstr(my_itoa(head->number), STDOUT_FILENO);
            my_putstr(")\n", STDOUT_FILENO);
        }
        head = head->next;
    }
    my_putstr("sont encore en vie au bout de 10 000 tours\n", STDOUT_FILENO);
    return EXIT_SUCCESS;
}

int main_loop(core_t *c)
{
    c->cycle = 0;
    while (check_live(c->proc, c->cycle) > 1) {
        if (c->cycle == 10001)
            return end_equality(c);
        if (c->nbr_cycle > 0 && c->cycle % c->nbr_cycle == 0)
            dump(c);
        execution_cycle(c);
        ++c->cycle;
    }
    who_last_live(c->proc, c->cycle);
    return EXIT_SUCCESS;
}
