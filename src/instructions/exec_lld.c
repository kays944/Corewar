/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** exec_lld
*/

#include "instr.h"

void exec_lld(core_t *c, process_t *proc)
{
    int pc = proc->pc;
    int t = (c->memory[(pc + 1) % MEM_SIZE] >> 6) & 3;
    int sz = (t == 2) ? 4 : 2;
    int src = pc + 2;
    short off = 0;
    int val = 0;

    if (t == 3) {
        off = (c->memory[(pc + 2) % MEM_SIZE] << 8)
            | c->memory[(pc + 3) % MEM_SIZE];
        src = pos_mod(pc + off, MEM_SIZE);
    }
    val = (c->memory[src % MEM_SIZE] << 24)
        + (c->memory[(src + 1) % MEM_SIZE] << 16)
        + (c->memory[(src + 2) % MEM_SIZE] << 8)
        + c->memory[(src + 3) % MEM_SIZE];
    proc->registers[c->memory[(pc + 2 + sz) % MEM_SIZE] - 1] = val;
    proc->carry = (val == 0);
    proc->pc = (pc + 3 + sz) % MEM_SIZE;
    proc->next_execution = 10;
}
