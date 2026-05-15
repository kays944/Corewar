/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** exec_and
*/

#include "instr.h"

void exec_and(core_t *c, process_t *proc)
{
    int pc = proc->pc;
    int cb = c->memory[(pc + 1) % MEM_SIZE];
    int p = pc + 2;
    int a = read_arg(c, proc, (cb >> 6) & 3, &p);
    int b = read_arg(c, proc, (cb >> 4) & 3, &p);
    int r = c->memory[p % MEM_SIZE];
    int res = a & b;

    if (valid_reg(r))
        proc->registers[r - 1] = res;
    proc->carry = (res == 0);
    proc->pc = (p + 1) % MEM_SIZE;
    proc->next_execution = 6;
}
