/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** my_puthex.c
*/

#include <unistd.h>

void my_put_hex(unsigned long value, int width, int canal)
{
    char hex[] = "0123456789ABCDEF";
    char buf[16];
    int i = width - 1;

    while (i >= 0) {
        buf[i] = hex[value & 0xF];
        value >>= 4;
        i--;
    }
    write(canal, buf, width);
}
