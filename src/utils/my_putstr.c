/*
** EPITECH PROJECT, 2025
** mysh1
** File description:
** my_putstr.c
*/

#include <unistd.h>
#include "utils.h"

void my_putstr(char *str, int canal)
{
    if (str == NULL)
        return;
    write(canal, str, my_strlen(str));
}
