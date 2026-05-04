/*
** EPITECH PROJECT, 2025
** my_strdup
** File description:
** dup
*/
#include <stdlib.h>

static int lenlof(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}

char *my_strdup(char const *src)
{
    int i = 0;
    int len = lenlof(src) + 1;
    char *copy = NULL;

    copy = malloc(len * sizeof(char));
    if (!copy)
        return NULL;
    while (src[i]) {
        copy[i] = src[i];
        i++;
    }
    copy[i] = '\0';
    return copy;
}
