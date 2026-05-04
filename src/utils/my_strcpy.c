/*
** EPITECH PROJECT, 2025
** my_strcpy.c
** File description:
** my strcpy
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i]) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
