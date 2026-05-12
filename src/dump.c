/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** dump.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "struct.h"
#include "utils.h"

void dump(core_t *c, size_t cycle)
{
    process_t *head = c->proc;

    my_putstr("CYCLE : ", STDOUT_FILENO);
    my_putstr(my_itoa(cycle), STDOUT_FILENO);
    my_putstr("\n", STDOUT_FILENO);
    while (head) {
        if (cycle - head->last_live <= CYCLE_TO_DIE) {
            my_putstr(head->champion->name, STDOUT_FILENO);
            my_putstr(" IS ALIVE\n", STDOUT_FILENO);
        } else {
            my_putstr(head->champion->name, STDOUT_FILENO);
            my_putstr(" IS DEAD\n", STDOUT_FILENO);
        }
        head = head->next;
    }
}
