/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** corewar.c
*/

#include "corewar.h"
#include "macros.h"
#include "utils.h"
#include <stdio.h>

int corewar(int argc, char **argv)
{
    if (my_strcmp(argv[1], "-h") == CMP_SUCCESS)
        return helper();
    printf("HelloWorld\n");
    return EXIT_SUCCESS;
}
