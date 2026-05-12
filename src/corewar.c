/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** corewar.c
*/

#include <stdio.h>
#include "corewar.h"
#include "macros.h"
#include "utils.h"
#include "struct.h"

int corewar(int argc, char **argv)
{
    core_t c = {0};

    if (my_strcmp(argv[IDX_FLAG_HELP], CHAR_FLAG_HELP) == CMP_SUCCESS)
        return helper();
    if (parsing(argc, argv, &c) == EXIT_FAIL || read_champions(&c)
        == EXIT_FAIL || init_proc(&c) == EXIT_FAIL)
        return EXIT_FAIL;
    return main_loop(&c);
}
