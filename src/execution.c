/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** execution
*/

#include <stdio.h>

#include <unistd.h>
#include <stdlib.h>
#include "struct.h"
#include "utils.h"
#include "macros.h"
#include "op.h"

int get_param_type(char coding_byte, int param_num)
{
    return (coding_byte >> (6 - param_num * 2)) & 0x03;
}

static int is_coding_byte(int opcode)
{
    if (opcode == 1 || opcode == 9 || opcode == 12 || opcode == 15)
        return EXIT_FAIL;
    return EXIT_SUCCESS;
}

static int is_index(int opcode)
{
    if (opcode == 9 || opcode == 10 || opcode == 11 || opcode == 12
        || opcode == 14 || opcode == 15)
        return EXIT_FAIL;
    return EXIT_SUCCESS;
}

static void execution_proc(core_t *c, process_t *proc)
{
    char opcode = c->memory[proc->pc];
    char coding_byte = 0;

    if (opcode < 1 || opcode > 16)
        my_putstr("invalid opcode\n", STDERR_FILENO);
    if (is_coding_byte(opcode) == EXIT_SUCCESS) {
        coding_byte = c->memory[proc->pc + 1];
    }
    printf("%s execute %s\n", proc->champion->name, op_tab[opcode].mnemonique);
}

int execution_cycle(core_t *c)
{
    process_t *head = c->proc;

    while (head) {
        if (head->next_execution == 1) {
            execution_proc(c, head);
        }
        head = head->next;
    }
    return EXIT_SUCCESS;
}
