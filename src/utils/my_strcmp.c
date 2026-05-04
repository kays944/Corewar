/*
** EPITECH PROJECT, 2025
** my_strcmp
** File description:
** compar two strings
*/

#include "macros.h"
#include <stdio.h>

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int s1_value = 0;
    int s2_value = 0;

    if (s1 == NULL || s2 == NULL)
        return EXIT_FAIL;
    while (s1[i] || s2[i]) {
        if (s1[i] != s2[i]) {
            s1_value = s1[i];
            s2_value = s2[i];
            break;
        }
        i++;
    }
    return (s1_value - s2_value);
}
