/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** corewar.h
*/

#ifndef COREWAR_H_
    #define COREWAR_H_
    #include <stdlib.h>
    #include "struct.h"

int corewar(int argc, char **argv);
int helper(void);
int parsing(int argc, char **argv, core_t *c);
int read_champions(core_t *c);
int init_proc(core_t *c);
int init_memory(core_t *c);
int main_loop(core_t *c);
void dump(core_t *c, size_t cycle);
int execution_cycle(core_t *c);

#endif
