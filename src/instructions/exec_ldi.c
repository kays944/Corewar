/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** exec_ldi
*/

#include "instr.h"

void exec_ldi(core_t *c, process_t *proc)
{
    int pc = proc->pc;
    int cb = c->memory[(pc + 1) % MEM_SIZE];
    int p = pc + 2;
    int a = read_idx(c, proc, (cb >> 6) & 3, &p);
    int b = read_idx(c, proc, (cb >> 4) & 3, &p);
    int off = pos_mod(a + b, IDX_MOD);
    int r = c->memory[p % MEM_SIZE];
    int val = 0;

    val = (c->memory[(pc + off) % MEM_SIZE] << 24)
        + (c->memory[(pc + off + 1) % MEM_SIZE] << 16)
        + (c->memory[(pc + off + 2) % MEM_SIZE] << 8)
        + c->memory[(pc + off + 3) % MEM_SIZE];
    proc->registers[r - 1] = val;
    proc->carry = (val == 0);
    proc->pc = (p + 1) % MEM_SIZE;
}
