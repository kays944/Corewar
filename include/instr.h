/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** instr.h
*/

#ifndef INSTR_H_
    #define INSTR_H_
    #include <stdlib.h>
    #include "struct.h"

void exec_add(core_t *c, process_t *proc);
void exec_and(core_t *c, process_t *proc);
void exec_fork(core_t *c, process_t *proc);
void exec_ld(core_t *c, process_t *proc);
void exec_ldi(core_t *c, process_t *proc);
void exec_lfork(core_t *c, process_t *proc);
void exec_live(core_t *c, process_t *proc);
void exec_lld(core_t *c, process_t *proc);
void exec_lldi(core_t *c, process_t *proc);
void exec_or(core_t *c, process_t *proc);
void exec_print(core_t *c, process_t *proc);
void exec_st(core_t *c, process_t *proc);
void exec_sti(core_t *c, process_t *proc);
void exec_sub(core_t *c, process_t *proc);
void exec_xor(core_t *c, process_t *proc);
void exec_zjmp(core_t *c, process_t *proc);

int pos_mod(int x, int n);
int read_arg(core_t *c, process_t *p, int t, int *pos);
int read_idx(core_t *c, process_t *p, int t, int *pos);
int read_lidx(core_t *c, process_t *p, int t, int *pos);

typedef void (*exec_func_t)(core_t *, process_t *);

#endif
