/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** exec_add
*/

#include "instr.h"

void exec_add(core_t *c, process_t *proc)
{
    int pc = proc->pc;
    int r1 = c->memory[(pc + 2) % MEM_SIZE];
    int r2 = c->memory[(pc + 3) % MEM_SIZE];
    int r3 = c->memory[(pc + 4) % MEM_SIZE];
    int val = proc->registers[r1 - 1] + proc->registers[r2 - 1];

    proc->registers[r3 - 1] = val;
    proc->carry = (val == 0);
    proc->pc = (pc + 5) % MEM_SIZE;
}
