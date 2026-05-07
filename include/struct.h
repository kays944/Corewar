/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** struct.h
*/

#ifndef STRUCT_H_
    #define STRUCT_H_
    #include "op.h"
typedef struct param_ch_s {
    char *name;
    int number;
    int position;
    header_t header;
    unsigned char *bytecode;
    struct param_ch_s *next;
} param_ch_t;

typedef struct option_s {
    int nbr_cycle;
    int nb_champions;
    param_ch_t *champions;
    unsigned char memory[MEM_SIZE];
} option_t;

typedef struct process_s {
    int registers[REG_NUMBER];
    int pc;
    int carry;
    int last_live;
    int number;
    struct process_s *next;
} process_t;

#endif
