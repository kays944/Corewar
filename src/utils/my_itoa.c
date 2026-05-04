/*
** EPITECH PROJECT, 2025
** mysh1
** File description:
** my_itoa.c
*/

#include <stdlib.h>

char *my_itoa(int n)
{
    char *str;
    int len = (n == 0) ? 1 : 0;
    int tmp = n;

    while (tmp > 0) {
        len++;
        tmp /= 10;
    }
    str = malloc(len + 1);
    if (!str)
        return NULL;
    str[len] = '\0';
    if (n == 0)
        str[0] = '0';
    while (n > 0) {
        --len;
        str[len] = (n % 10) + '0';
        n /= 10;
    }
    return str;
}
