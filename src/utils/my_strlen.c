/*
** EPITECH PROJECT, 2025
** mysh1
** File description:
** my_strlen.c
*/

#include <stdio.h>

int my_strlen(char *str)
{
    int i = 0;

    if (str == NULL)
        return 0;
    for (; str[i] != '\0'; ++i)
        continue;
    return i;
}
