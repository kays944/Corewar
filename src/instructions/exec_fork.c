/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** exec_fork
*/

#include <stdlib.h>
#include "instr.h"

void exec_fork(core_t *c, process_t *proc)
{
    int pc = proc->pc;
    short off = (c->memory[(pc + 1) % MEM_SIZE] << 8)
        | c->memory[(pc + 2) % MEM_SIZE];
    int idx = pos_mod(off, IDX_MOD);
    process_t *np = malloc(sizeof(process_t));

    if (!np)
        return;
    for (int i = 0; i < REG_NUMBER; i++)
        np->registers[i] = proc->registers[i];
    np->pc = (pc + idx) % MEM_SIZE;
    np->carry = proc->carry;
    np->last_live = proc->last_live;
    np->number = proc->number;
    np->champion = proc->champion;
    np->next_execution = proc->next_execution;
    np->next = c->proc;
    c->proc = np;
    proc->pc = (pc + 3) % MEM_SIZE;
    proc->next_execution = 800;
}
