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
#include "instr.h"

const exec_func_t exec_tab[17] = {
    NULL,
    exec_live,
    exec_ld,
    exec_st,
    exec_add,
    exec_sub,
    exec_and,
    exec_or,
    exec_xor,
    exec_zjmp,
    exec_ldi,
    exec_sti,
    exec_fork,
    exec_lld,
    exec_lldi,
    exec_lfork,
    exec_print
};

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

int get_size_param(int type, int opcode)
{
    if (type == T_REG)
        return REGISTER_SIZE;
    if (type == T_DIR && is_index(opcode) == EXIT_SUCCESS)
        return DIR_SIZE;
    if (type == T_DIR && is_index(opcode) == EXIT_FAIL)
        return IND_SIZE;
    if (type == T_IND)
        return IND_SIZE;
    return EXIT_FAIL;
}

static void execution_proc(core_t *c, process_t *proc)
{
    char opcode = c->memory[proc->pc];

    if (opcode < 1 || opcode > 16)
        my_putstr("invalid opcode\n", STDERR_FILENO);
    exec_tab[opcode](c, proc);
}

int execution_cycle(core_t *c)
{
    process_t *head = c->proc;

    while (head) {
        if (head->next_execution == 1)
            execution_proc(c, head);
        else
            --head->next_execution;
        head = head->next;
    }
    return EXIT_SUCCESS;
}
