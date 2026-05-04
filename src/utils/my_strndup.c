/*
** EPITECH PROJECT, 2025
** my_strndup
** File description:
** n dup
*/

#include <stdlib.h>

char *my_strndup(char const *src, int n)
{
    int i = 0;
    int len = n + 1;
    char *copy = NULL;

    copy = malloc(len * sizeof(char));
    if (!copy)
        return NULL;
    for (; i != n; ++i)
        copy[i] = src[i];
    copy[i] = '\0';
    return copy;
}
