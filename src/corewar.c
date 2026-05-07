/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** corewar.c
*/

#include "corewar.h"
#include "macros.h"
#include "utils.h"
#include "struct.h"
#include <stdio.h>

int corewar(int argc, char **argv)
{
    option_t opt = {0};
    process_t proc = {0};

    if (my_strcmp(argv[IDX_FLAG_HELP], CHAR_FLAG_HELP) == CMP_SUCCESS)
        return helper();
    if (parsing(argc, argv, &opt) == EXIT_FAIL || read_champions(&opt)
        == EXIT_FAIL)
        return EXIT_FAIL;
    return EXIT_SUCCESS;
}
