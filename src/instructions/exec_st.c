/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** exec_st
*/

#include "instr.h"

static void st_to_mem(core_t *c, process_t *proc, int pc, int val)
{
    short off = 0;
    int dst = 0;

    off = (c->memory[(pc + 3) % MEM_SIZE] << 8)
        | c->memory[(pc + 4) % MEM_SIZE];
    dst = pc + pos_mod(off, IDX_MOD);
    c->memory[(dst) % MEM_SIZE] = (val >> 24) & 0xFF;
    c->memory[(dst + 1) % MEM_SIZE] = (val >> 16) & 0xFF;
    c->memory[(dst + 2) % MEM_SIZE] = (val >> 8) & 0xFF;
    c->memory[(dst + 3) % MEM_SIZE] = val & 0xFF;
    proc->pc = (pc + 5) % MEM_SIZE;
    proc->next_execution = 5;
}

void exec_st(core_t *c, process_t *proc)
{
    int pc = proc->pc;
    int t = (c->memory[(pc + 1) % MEM_SIZE] >> 4) & 3;
    int src_r = c->memory[(pc + 2) % MEM_SIZE];
    int val = valid_reg(src_r) ? proc->registers[src_r - 1] : 0;
    int dst_r = c->memory[(pc + 3) % MEM_SIZE];

    if (t == 1) {
        if (valid_reg(dst_r))
            proc->registers[dst_r - 1] = val;
        proc->pc = (pc + 4) % MEM_SIZE;
        proc->next_execution = 5;
        return;
    }
    st_to_mem(c, proc, pc, val);
}
