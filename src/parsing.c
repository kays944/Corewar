/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** parsing.c
*/

#include "macros.h"
#include "utils.h"
#include "struct.h"
#include <stdlib.h>
#include <unistd.h>

int parsing_dump(option_t *opt, char *flag, char *nbr_cycles)
{
    size_t idx = 0;

    if (my_strcmp(flag, CHAR_FLAG_DUMP) == CMP_SUCCESS && nbr_cycles) {
        opt->nbr_cycle = my_getnbr(nbr_cycles);
        idx = NEXT_IDX_IF_DUMP;
    } else {
        opt->nbr_cycle = NBR_CYCLES_DEFAULT;
        idx = NEXT_IDX_IF_NOT_DUMP;
    }
    return idx;
}

int parsing_one(char **argv, int idx, param_ch_t *node)
{
    int nbr = 0;
    int pos = 0;
    char *name = NULL;

    if (my_strcmp(argv[idx], CHAR_FLAG_NBR) == CMP_SUCCESS && argv[idx + 1]) {
        nbr = my_getnbr(argv[idx + 1]);
        idx += 2;
    }
    if (my_strcmp(argv[idx], CHAR_FLAG_POS) == CMP_SUCCESS && argv[idx + 1]) {
        pos = my_getnbr(argv[idx + 1]);
        idx += 2;
    }
    if (argv[idx] && *argv[idx] != CHAR_FLAG)
        name = argv[idx];
    else
        return PARSING_ERROR;
    node->name = my_strdup(name);
    node->number = nbr;
    node->position = pos;
    return idx + 1;
}

int parsing(int argc, char **argv, option_t *opt)
{
    int i = parsing_dump(opt, argv[IDX_FLAG_DUMP], argv[IDX_FLAG_NBR_CYCLE]);
    param_ch_t *head = NULL;
    param_ch_t *node = NULL;
    param_ch_t *current = NULL;

    for (; argv[i];) {
        node = malloc(sizeof(param_ch_t));
        i = parsing_one(argv, i, node);
        if (i == PARSING_ERROR)
            return EXIT_FAIL;
        if (!head)
            head = node;
        else
            current->next = node;
        current = node;
    }
    opt->champions = head;
    return EXIT_SUCCESS;
}
