/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** free_all.c
*/

#include <stdlib.h>
#include "struct.h"

static void free_procs(process_t *proc)
{
    process_t *head = proc;

    while (head) {
        free(proc);
        head = head->next;
    }
}

static void free_champions(champ_t *ch)
{
    champ_t *head = ch;

    while (head) {
        free(head->name);
        free(head->bytecode);
        free(head);
        head = head->next;
    }
}

void free_all(core_t *c)
{
    free_procs(c->proc);
    free_champions(c->champions);
    c->proc = NULL;
    c->champions = NULL;
}
