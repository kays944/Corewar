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
int parsing(int argc, char **argv, option_t *opt);
int read_champions(option_t *opt);

#endif
