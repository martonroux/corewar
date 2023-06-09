/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-corewar-louis.rollet
** File description:
** sti
*/

#include "corewar.h"

int instruction_sti(corewar_t *corewar, instruction_t *instruction)
{
    if (instruction->args_type[0] != T_REG ||
    !check_instruction_args(instruction))
        return 1;
    if (instruction->args_type[1] == T_REG)
        instruction->args[1] = instruction->champion->registers[instruction->
        args[1] - 1];
    if (instruction->args_type[2] == T_REG)
        instruction->args[2] = instruction->champion->registers[instruction->
        args[2] - 1];
    int pc = (instruction->memory_pos + (instruction->args[1] +
        instruction->args[2]) % IDX_MOD) % MEM_SIZE;
    pc = pc < 0 ? MEM_SIZE + pc : pc;
    write_in_memory(corewar, pc,
        instruction->champion->registers[instruction->args[0] - 1], 4);
    for (int i = 0; i < 4; i++)
        corewar->memory_owner[pc + i] =
            (char) (instruction->champion->id + 1);
    return 0;
}
