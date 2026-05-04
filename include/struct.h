/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** struct.h
*/

#ifndef STRUCT_H_
    #define STRUCT_H_

typedef struct param_ch_s {
    char *name;
    int number;
    int position;
    struct param_ch_s *next;
} param_ch_t;

typedef struct option_s {
    int nbr_cycle;
    param_ch_t *champions;
} option_t;

#endif
