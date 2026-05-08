/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** get_pos.c
*/

#include "struct.h"
#include "macros.h"
#include <stdlib.h>
#include <stdio.h>

static int count_champions(param_ch_t *head)
{
    int count = 0;

    while (head) {
        ++count;
        head = head->next;
    }
    return count;
}

static int get_best_pos(unsigned char mem[])
{
    int current = 0;
    int bigger = 0;
    int idx_bigger = 0;

    for (int i = 0; i != MEM_SIZE; ++i) {
        if (mem[i] == 0)
            ++current;
        if (mem[i] == 0 && (mem[i + 1] != 0 || !mem[i + 1])
            && current > bigger) {
            bigger = current - 1;
            idx_bigger = i - bigger;
        }
        if (mem[i] == 0 && mem[i + 1] != 0)
            current = 0;
    }
    return (bigger / 2) + idx_bigger;
}

static void put_in_memory(unsigned char mem[], param_ch_t *head)
{
    for (size_t i = 0; i != head->header.prog_size; ++i)
        mem[(head->position + i) % MEM_SIZE] = head->bytecode[i];
}

int init_memory(option_t *opt)
{
    param_ch_t *head = opt->champions;

    opt->nb_champions = count_champions(opt->champions);
    while (head) {
        if (head->position != -1)
            head->position = head->position % MEM_SIZE;
        if (head->position == -1)
            head->position = get_best_pos(opt->memory);
        put_in_memory(opt->memory, head);
        head = head->next;
    }
    return EXIT_SUCCESS;
}
