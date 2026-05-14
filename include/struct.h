/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** struct.h
*/

#ifndef STRUCT_H_
    #define STRUCT_H_
    #include "op.h"

typedef struct champ_s {
    char *name;
    int number;
    int position;
    header_t header;
    unsigned char *bytecode;
    struct champ_s *next;
} champ_t;

typedef struct process_s {
    int registers[REG_NUMBER];
    int pc;
    int carry;
    int last_live;
    int number;
    champ_t *champion;
    int next_execution;
    struct process_s *next;
} process_t;

typedef struct core_s {
    int nbr_cycle;
    int nb_champions;
    champ_t *champions;
    unsigned char memory[MEM_SIZE];
    process_t *proc;
    size_t cycle;
    int live_count;
    int cycle_to_die;
} core_t;

#endif
