/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** exec_lld
*/

#include "instr.h"

static int read_mem_4(core_t *c, int addr)
{
    return (c->memory[addr % MEM_SIZE] << 24)
        + (c->memory[(addr + 1) % MEM_SIZE] << 16)
        + (c->memory[(addr + 2) % MEM_SIZE] << 8)
        + c->memory[(addr + 3) % MEM_SIZE];
}

void exec_lld(core_t *c, process_t *proc)
{
    int pc = proc->pc;
    int t = (c->memory[(pc + 1) % MEM_SIZE] >> 6) & 3;
    int sz = (t == 2) ? 4 : 2;
    int src = pc + 2;
    short off = 0;
    int val = 0;
    int dst_r = 0;

    if (t == 3) {
        off = (c->memory[(pc + 2) % MEM_SIZE] << 8)
            | c->memory[(pc + 3) % MEM_SIZE];
        src = pos_mod(pc + off, MEM_SIZE);
    }
    val = read_mem_4(c, src);
    dst_r = c->memory[(pc + 2 + sz) % MEM_SIZE];
    if (valid_reg(dst_r))
        proc->registers[dst_r - 1] = val;
    proc->carry = (val == 0);
    proc->pc = (pc + 3 + sz) % MEM_SIZE;
    proc->next_execution = 10;
}
