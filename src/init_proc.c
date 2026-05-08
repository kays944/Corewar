/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** init_proc.c
*/

#include "struct.h"
#include "macros.h"
#include <stdio.h>
#include <stdlib.h>

void new_proc(param_ch_t *ch, process_t *node)
{
    node->number = ch->number;
    node->pc = ch->position;
    node->carry = 0;
    node->last_live = 0;
    for (size_t i = 0; i < REG_NUMBER; ++i)
        node->registers[i] = 0;
    node->registers[0] = ch->number;
    node->next = NULL;
}

int init_proc(option_t *opt)
{
    param_ch_t *ch = opt->champions;
    process_t *head = NULL;
    process_t *node = NULL;
    process_t *current = NULL;

    while (ch) {
        node = malloc(sizeof(process_t));
        if (!node)
            return EXIT_FAIL;
        new_proc(ch, node);
        if (!head)
            head = node;
        else
            current->next = node;
        current = node;
        ch = ch->next;
    }
    opt->proc = head;
    return EXIT_SUCCESS;
}
