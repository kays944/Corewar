/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** parsing.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "macros.h"
#include "utils.h"
#include "struct.h"

int parsing_dump(core_t *c, char *flag, char *nbr_cycles)
{
    size_t idx = 0;

    if (my_strcmp(flag, CHAR_FLAG_DUMP) == CMP_SUCCESS && nbr_cycles) {
        c->nbr_cycle = my_getnbr(nbr_cycles);
        idx = NEXT_IDX_IF_DUMP;
    } else {
        c->nbr_cycle = NBR_CYCLES_DEFAULT;
        idx = NEXT_IDX_IF_NOT_DUMP;
    }
    return idx;
}

int parsing_one(char **argv, int idx, champ_t *node)
{
    node->number = -1;
    node->position = -1;
    node->name = NULL;
    if (my_strcmp(argv[idx], CHAR_FLAG_NBR) == CMP_SUCCESS && argv[idx + 1]) {
        node->number = my_getnbr(argv[idx + 1]);
        idx += 2;
    }
    if (my_strcmp(argv[idx], CHAR_FLAG_POS) == CMP_SUCCESS && argv[idx + 1]) {
        node->position = my_getnbr(argv[idx + 1]);
        idx += 2;
    }
    if (argv[idx] && *argv[idx] != CHAR_FLAG)
        node->name = my_strdup(argv[idx]);
    else {
        free(node);
        return PARSING_ERROR;
    }
    return idx + 1;
}

int parsing(int argc, char **argv, core_t *c)
{
    champ_t *head = NULL;
    champ_t *node = NULL;
    champ_t *current = NULL;

    for (int i = parsing_dump(c, argv[IDX_FLAG_DUMP],
            argv[IDX_FLAG_NBR_CYCLE]); argv[i];) {
        node = malloc(sizeof(champ_t));
        if (!node)
            return EXIT_FAIL;
        i = parsing_one(argv, i, node);
        if (i == PARSING_ERROR)
            return EXIT_FAIL;
        if (!head)
            head = node;
        else
            current->next = node;
        current = node;
    }
    c->champions = head;
    return EXIT_SUCCESS;
}
