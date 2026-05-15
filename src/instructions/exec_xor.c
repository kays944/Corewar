/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** exec_xor
*/

#include "instr.h"

void exec_xor(core_t *c, process_t *proc)
{
    int pc = proc->pc;
    int cb = c->memory[(pc + 1) % MEM_SIZE];
    int p = pc + 2;
    int left = read_arg(c, proc, (cb >> 6) & 3, &p);
    int right = read_arg(c, proc, (cb >> 4) & 3, &p);
    int reg = c->memory[p % MEM_SIZE];
    int xored = left ^ right;

    if (valid_reg(reg))
        proc->registers[reg - 1] = xored;
    proc->carry = (xored == 0);
    proc->pc = (p + 1) % MEM_SIZE;
    proc->next_execution = 6;
}
