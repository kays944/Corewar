/*
** EPITECH PROJECT, 2025
** my_strncpy.c
** File description:
** my strncpy
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int end = 0;

    while (i < n) {
        if (src[i] == '\0') {
            dest[i] = '\0';
            end = 1;
        }
        if (end == 1)
            dest[i] = '\0';
        if (end == 0)
            dest[i] = src[i];
        i++;
    }
    return dest;
}
