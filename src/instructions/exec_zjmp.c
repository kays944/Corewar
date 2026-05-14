/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** exec_zjmp
*/

#include "instr.h"

void exec_zjmp(core_t *c, process_t *proc)
{
    int pc = proc->pc;
    short off = (c->memory[(pc + 1) % MEM_SIZE] << 8)
        | c->memory[(pc + 2) % MEM_SIZE];

    if (proc->carry)
        proc->pc = pos_mod(pc + off, MEM_SIZE);
    else
        proc->pc = (pc + 3) % MEM_SIZE;
}
