/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** execution
*/

#include <unistd.h>
#include <stdlib.h>
#include "struct.h"
#include "utils.h"
#include "macros.h"
#include "op.h"
#include "instr.h"
#include "corewar.h"

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
    for (size_t i = 0; opcode_no_coding_byte[i]; ++i)
        if (opcode == opcode_no_coding_byte[i])
            return EXIT_FAIL;
    return EXIT_SUCCESS;
}

static int is_index(int opcode)
{
    for (size_t i = 0; opcode_index[i]; ++i)
        if (opcode == opcode_index[i])
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

static int execution_proc(core_t *c, process_t *proc)
{
    unsigned char opcode = c->memory[proc->pc];

    if (opcode < FIRST_OPCODE || opcode > LAST_OPCODE) {
        proc->pc = (proc->pc + 1) % MEM_SIZE;
        proc->next_execution = NEXT_EXECUTION + 1;
        return EXIT_SUCCESS;
    }
    exec_tab[opcode](c, proc);
    return EXIT_SUCCESS;
}

int execution_cycle(core_t *c)
{
    process_t *head = c->proc;
    int exit_code = 0;

    while (head) {
        if (head->next_execution == NEXT_EXECUTION)
            exit_code = execution_proc(c, head);
        if (exit_code == EXIT_FAIL)
            return EXIT_FAIL;
        else
            --head->next_execution;
        head = head->next;
    }
    return EXIT_SUCCESS;
}
