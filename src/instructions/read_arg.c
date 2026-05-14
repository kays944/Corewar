/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** read_arg
*/

#include "instr.h"

int pos_mod(int x, int n)
{
    int r = x % n;

    if (r < 0)
        r += n;
    return r;
}

int read_arg(core_t *c, process_t *p, int t, int *pos)
{
    int b = *pos;
    short off = 0;
    int addr = b;

    if (t == 1) {
        *pos += 1;
        return p->registers[c->memory[b % MEM_SIZE] - 1];
    }
    if (t == 3) {
        off = (c->memory[b % MEM_SIZE] << 8) | c->memory[(b + 1) % MEM_SIZE];
        addr = p->pc + pos_mod(off, IDX_MOD);
        *pos += 2;
    } else
        *pos += 4;
    return (c->memory[addr % MEM_SIZE] << 24)
        + (c->memory[(addr + 1) % MEM_SIZE] << 16)
        + (c->memory[(addr + 2) % MEM_SIZE] << 8)
        + c->memory[(addr + 3) % MEM_SIZE];
}

int read_idx(core_t *c, process_t *p, int t, int *pos)
{
    int b = *pos;
    short s = 0;
    int addr = 0;

    if (t == 1) {
        *pos += 1;
        return p->registers[c->memory[b % MEM_SIZE] - 1];
    }
    s = (c->memory[b % MEM_SIZE] << 8) | c->memory[(b + 1) % MEM_SIZE];
    *pos += 2;
    if (t == 2)
        return s;
    addr = (p->pc + pos_mod(s, IDX_MOD)) % MEM_SIZE;
    return (c->memory[addr] << 8) | c->memory[(addr + 1) % MEM_SIZE];
}

int read_lidx(core_t *c, process_t *p, int t, int *pos)
{
    int start = *pos;
    short val = 0;
    int mem_addr = 0;

    if (t == 1) {
        *pos += 1;
        return p->registers[c->memory[start % MEM_SIZE] - 1];
    }
    val = (c->memory[start % MEM_SIZE] << 8)
        | c->memory[(start + 1) % MEM_SIZE];
    *pos += 2;
    if (t == 2)
        return val;
    mem_addr = pos_mod(p->pc + val, MEM_SIZE);
    return (c->memory[mem_addr] << 8) | c->memory[(mem_addr + 1) % MEM_SIZE];
}
