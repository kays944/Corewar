/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** corewar.h
*/

#ifndef COREWAR_H_
    #define COREWAR_H_
    #include "struct.h"

int corewar(int argc, char **argv);
int helper(void);
int parsing(int argc, char **argv, core_t *opt);
int read_champions(core_t *opt);
int init_proc(core_t *opt);
int init_memory(core_t *opt);
int main_loop(core_t *opt);

#endif
