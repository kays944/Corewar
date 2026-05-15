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

static void delete_proc(core_t *c, process_t *node_delete)
{
    process_t *current = c->proc;
    process_t *prev = NULL;

    while (current && current != node_delete) {
        prev = current;
        current = current->next;
    }
    if (!current)
        return;
    if (prev)
        prev->next = current->next;
    else
        c->proc = current->next;
    free(current);
}

static int check_live(process_t *proc, core_t *c)
{
    int count_proc_live = 0;
    process_t *head = proc;
    process_t *next = NULL;

    while (head) {
        next = head->next;
        if (c->cycle - head->last_live <= c->cycle_to_die)
            count_proc_live++;
        else
            delete_proc(c, head);
        head = next;
    }
    return count_proc_live;
}

static int who_last_live(process_t *proc, core_t *c)
{
    process_t *winner = NULL;

    while (proc) {
        if ((c->cycle - proc->last_live <= c->cycle_to_die) && (!winner
                || proc->last_live > winner->last_live)) {
            winner = proc;
        }
        proc = proc->next;
    }
    if (!winner)
        return EXIT_FAIL;
    if (winner != NULL) {
        my_putstr(winner->champion->header.prog_name, STDOUT_FILENO);
        my_putstr(" is winner !\n", STDOUT_FILENO);
    }
    return EXIT_SUCCESS;
}

int main_loop(core_t *c)
{
    c->cycle = 0;
    c->live_count = 0;
    c->cycle_to_die = CYCLE_TO_DIE;
    while (check_live(c->proc, c) > 1) {
        if (c->cycle_to_die <= 0) {
            my_putstr("Egalite !\n", STDOUT_FILENO);
            return EXIT_SUCCESS;
        }
        if (c->nbr_cycle > 0 && c->cycle % c->nbr_cycle == 0)
            dump(c);
        if (execution_cycle(c) == EXIT_FAIL)
            return EXIT_FAIL;
        ++c->cycle;
    }
    if (!c->proc) {
        my_putstr("Tous les champions sont mort en meme temps\n",
            STDOUT_FILENO);
        return EXIT_SUCCESS;
    }
    return who_last_live(c->proc, c);
}
