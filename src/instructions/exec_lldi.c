/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** exec_lldi
*/

#include "instr.h"

void exec_lldi(core_t *c, process_t *proc)
{
    int pc = proc->pc;
    int cb = c->memory[(pc + 1) % MEM_SIZE];
    int p = pc + 2;
    int a = read_lidx(c, proc, (cb >> 6) & 3, &p);
    int b = read_lidx(c, proc, (cb >> 4) & 3, &p);
    int addr = pos_mod(pc + a + b, MEM_SIZE);
    int reg = c->memory[p % MEM_SIZE];
    int val = 0;

    val = (c->memory[addr % MEM_SIZE] << 24)
        + (c->memory[(addr + 1) % MEM_SIZE] << 16)
        + (c->memory[(addr + 2) % MEM_SIZE] << 8)
        + c->memory[(addr + 3) % MEM_SIZE];
    proc->registers[reg - 1] = val;
    proc->carry = (val == 0);
    proc->pc = (p + 1) % MEM_SIZE;
}
