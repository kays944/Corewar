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
#include "macros.h"

void dump_status(process_t *proc, core_t *c)
{
    if (c->cycle - proc->last_live <= c->cycle_to_die) {
        my_putstr(proc->champion->header.prog_name, STDOUT_FILENO);
        my_putstr("(", STDOUT_FILENO);
        my_putnbr(proc->number, STDOUT_FILENO);
        my_putstr("): alive\n", STDOUT_FILENO);
    } else {
        my_putstr(proc->champion->header.prog_name, STDOUT_FILENO);
        my_putstr("(", STDOUT_FILENO);
        my_putnbr(proc->number, STDOUT_FILENO);
        my_putstr("): dead\n", STDOUT_FILENO);
    }
}

void dump_registers(process_t *proc)
{
    for (int i = 0; i < REG_NUMBER; i++) {
        my_putstr("r", STDOUT_FILENO);
        my_putnbr(i + 1, STDOUT_FILENO);
        my_putstr(": ", STDOUT_FILENO);
        my_put_hex(proc->registers[i], SIZE_BYTE, STDOUT_FILENO);
        if ((i + 1) % 6 != 0 && i != LAST_OPCODE - 1)
            my_putstr(" ", STDOUT_FILENO);
        else
            my_putstr("\n", STDOUT_FILENO);
    }
    my_putstr("PC : ", STDOUT_FILENO);
    my_put_hex(proc->pc, SIZE_BYTE, STDOUT_FILENO);
    my_putstr(" carry : ", STDOUT_FILENO);
    my_putnbr(proc->carry, STDOUT_FILENO);
    my_putstr("\n", STDOUT_FILENO);
    my_putstr("\n", STDOUT_FILENO);
}

void dump_memory(core_t *c)
{
    for (size_t i = 0; i < MEM_SIZE; i++) {
        if (i % BYTE_PER_LINE == 0) {
            my_putstr("\n", STDOUT_FILENO);
            my_put_hex(i, SIZE_BYTE, STDOUT_FILENO);
            my_putstr(": ", STDOUT_FILENO);
        }
        my_put_hex(c->memory[i], 2, STDOUT_FILENO);
        my_putstr(" ", STDOUT_FILENO);
    }
    my_putstr("\n", STDOUT_FILENO);
}

void dump(core_t *c)
{
    process_t *head = c->proc;

    my_putstr("\nCYCLE : ", STDOUT_FILENO);
    my_putnbr(c->cycle, STDOUT_FILENO);
    my_putstr("\n", STDOUT_FILENO);
    my_putstr("Registers:\n", STDOUT_FILENO);
    my_putstr("\n", STDOUT_FILENO);
    while (head) {
        dump_status(head, c);
        dump_registers(head);
        head = head->next;
    }
    my_putstr("Memory:", STDOUT_FILENO);
    dump_memory(c);
    my_putstr("\n", STDOUT_FILENO);
}
