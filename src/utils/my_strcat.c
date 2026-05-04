/*
** EPITECH PROJECT, 2025
** my_strcat.c
** File description:
** my strcat
*/

static int strlen_strcat(char *str)
{
    int i = 0;

    while (str[i]) {
        i++;
    }
    return i;
}

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int n = strlen_strcat(dest);

    while (src[i] != '\0'){
        dest[i + n] = src[i];
        i++;
    }
    dest[i + n] = '\0';
    return dest;
}
