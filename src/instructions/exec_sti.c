/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** exec_sti
*/

#include "instr.h"

void exec_sti(core_t *c, process_t *proc)
{
    int pc = proc->pc;
    int cb = c->memory[(pc + 1) % MEM_SIZE];
    int p = pc + 2;
    int src = c->memory[p % MEM_SIZE];
    int val = proc->registers[src - 1];
    int a = 0;
    int b = 0;
    int dst = 0;

    p += 1;
    a = read_idx(c, proc, (cb >> 4) & 3, &p);
    b = read_idx(c, proc, (cb >> 2) & 3, &p);
    dst = pc + pos_mod(a + b, IDX_MOD);
    c->memory[(dst) % MEM_SIZE] = (val >> 24) & 0xFF;
    c->memory[(dst + 1) % MEM_SIZE] = (val >> 16) & 0xFF;
    c->memory[(dst + 2) % MEM_SIZE] = (val >> 8) & 0xFF;
    c->memory[(dst + 3) % MEM_SIZE] = val & 0xFF;
    proc->pc = p % MEM_SIZE;
    proc->next_execution = 25;
}
