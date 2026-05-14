/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** exec_lfork
*/

#include <stdlib.h>
#include "instr.h"

void exec_lfork(core_t *c, process_t *proc)
{
    int pc = proc->pc;
    short off = (c->memory[(pc + 1) % MEM_SIZE] << 8)
        | c->memory[(pc + 2) % MEM_SIZE];
    int dst = pos_mod(pc + off, MEM_SIZE);
    process_t *np = malloc(sizeof(process_t));

    if (!np)
        return;
    *np = *proc;
    np->pc = dst;
    np->next = c->proc;
    c->proc = np;
    proc->pc = (pc + 3) % MEM_SIZE;
}
