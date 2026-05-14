/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** exec_ld
*/

#include "instr.h"

void exec_ld(core_t *c, process_t *proc)
{
    int pc = proc->pc;
    int t = (c->memory[(pc + 1) % MEM_SIZE] >> 6) & 3;
    int p = pc + 2;
    int val = read_arg(c, proc, t, &p);
    int r = c->memory[p % MEM_SIZE];

    proc->registers[r - 1] = val;
    proc->carry = (val == 0);
    proc->pc = (p + 1) % MEM_SIZE;
}
