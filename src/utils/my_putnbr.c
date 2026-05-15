/*
** EPITECH PROJECT, 2025
** mysh1
** File description:
** my_putstr.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "utils.h"

void my_putnbr(int nb, int canal)
{
    char *c_nb = my_itoa(nb);

    my_putstr(c_nb, STDOUT_FILENO);
    free(c_nb);
}
