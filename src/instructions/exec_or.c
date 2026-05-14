/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** exec_or
*/

#include "instr.h"

void exec_or(core_t *c, process_t *proc)
{
    int pc = proc->pc;
    int cb = c->memory[(pc + 1) % MEM_SIZE];
    int p = pc + 2;
    int val1 = read_arg(c, proc, (cb >> 6) & 3, &p);
    int val2 = read_arg(c, proc, (cb >> 4) & 3, &p);
    int dest = c->memory[p % MEM_SIZE];
    int result = val1 | val2;

    proc->registers[dest - 1] = result;
    proc->carry = (result == 0);
    proc->pc = (p + 1) % MEM_SIZE;
}
