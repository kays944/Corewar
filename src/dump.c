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

void write_hex(unsigned long value, int width, int canal)
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

void dump_status(process_t *proc, size_t cycle)
{
    if (cycle - proc->last_live <= CYCLE_TO_DIE) {
        my_putstr(proc->champion->header.prog_name, STDOUT_FILENO);
        my_putstr("(", STDOUT_FILENO);
        my_putstr(my_itoa(proc->number), STDOUT_FILENO);
        my_putstr("): alive\n", STDOUT_FILENO);
    } else {
        my_putstr(proc->champion->header.prog_name, STDOUT_FILENO);
        my_putstr("(", STDOUT_FILENO);
        my_putstr(my_itoa(proc->number), STDOUT_FILENO);
        my_putstr("): dead\n", STDOUT_FILENO);
    }
}

void dump_registers(process_t *proc)
{
    for (int i = 0; i < REG_NUMBER; i++) {
        my_putstr("r", STDOUT_FILENO);
        my_putstr(my_itoa(i + 1), STDOUT_FILENO);
        my_putstr(": ", STDOUT_FILENO);
        write_hex(proc->registers[i], 8, STDOUT_FILENO);
        if ((i + 1) % 6 != 0 && i != 15)
            my_putstr(" ", STDOUT_FILENO);
        else
            my_putstr("\n", STDOUT_FILENO);
    }
    my_putstr("PC : ", STDOUT_FILENO);
    write_hex(proc->pc, 8, STDOUT_FILENO);
    my_putstr(" carry : ", STDOUT_FILENO);
    my_putstr(my_itoa(proc->carry), STDOUT_FILENO);
    my_putstr("\n", STDOUT_FILENO);
    my_putstr("\n", STDOUT_FILENO);
}

void dump_memory(core_t *c)
{
    for (size_t i = 0; i < MEM_SIZE; i++) {
        if (i % 32 == 0) {
            my_putstr("\n", STDOUT_FILENO);
            write_hex(i, 8, STDOUT_FILENO);
            my_putstr(": ", STDOUT_FILENO);
        }
        write_hex(c->memory[i], 2, STDOUT_FILENO);
        my_putstr(" ", STDOUT_FILENO);
    }
    my_putstr("\n", STDOUT_FILENO);
}

void dump(core_t *c)
{
    process_t *head = c->proc;

    my_putstr("\nCYCLE : ", STDOUT_FILENO);
    my_putstr(my_itoa(c->cycle), STDOUT_FILENO);
    my_putstr("\n", STDOUT_FILENO);
    my_putstr("Registers:\n", STDOUT_FILENO);
    my_putstr("\n", STDOUT_FILENO);
    while (head) {
        dump_status(head, c->cycle);
        dump_registers(head);
        head = head->next;
    }
    my_putstr("Memory:", STDOUT_FILENO);
    dump_memory(c);
    my_putstr("\n", STDOUT_FILENO);
}
