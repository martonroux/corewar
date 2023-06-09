/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-corewar-louis.rollet
** File description:
** zjmp
*/

#include "corewar.h"

int instruction_zjmp(corewar_t *corewar, instruction_t *instruction)
{
    (void)corewar;
    if (!instruction->champion->carry) {
        instruction->memory_pos += instruction->size;
        return 0;
    }
    instruction->memory_pos =
        (instruction->memory_pos + instruction->args[0] % IDX_MOD) % MEM_SIZE;
    instruction->memory_pos = instruction->memory_pos < 0 ? MEM_SIZE + \
        instruction->memory_pos : instruction->memory_pos;
    return 0;
}
