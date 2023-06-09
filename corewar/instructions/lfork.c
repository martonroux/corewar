/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-corewar-louis.rollet
** File description:
** lfork
*/

#include "corewar.h"
#include "utils.h"

int instruction_lfork(corewar_t *corewar, instruction_t *instruction)
{
    instruction_t *new_instruction = copy_instruction(instruction);
    new_instruction->memory_pos =
            (instruction->memory_pos + instruction->args[0]) % MEM_SIZE;
    new_instruction->memory_pos = instruction->memory_pos < 0 ? MEM_SIZE + \
        instruction->memory_pos : instruction->memory_pos;
    first_read_instruction(corewar, new_instruction);
    list_append(corewar->instr_to_add, new_instruction);
    list_append(corewar->champions, new_instruction->champion);
    return 0;
}
