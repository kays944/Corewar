/*
** EPITECH PROJECT, 2025
** corewar
** File description:
** exec_print
*/

#include <unistd.h>
#include "instr.h"

void exec_print(core_t *c, process_t *proc)
{
    int pc = proc->pc;
    int r = c->memory[(pc + 2) % MEM_SIZE];
    unsigned char ch = proc->registers[r - 1] & 0xFF;

    write(STDOUT_FILENO, &ch, 1);
    proc->pc = (pc + 3) % MEM_SIZE;
    proc->next_execution = 2;
}
