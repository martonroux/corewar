/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-corewar-louis.rollet
** File description:
** lldi
*/

#include "corewar.h"

int instruction_lldi(corewar_t *corewar, instruction_t *instruction)
{
    (void)corewar;
    if (instruction->args_type[2] != T_REG ||
    !check_instruction_args(instruction))
        return 1;
    if (instruction->args_type[0] == T_REG)
        instruction->args[0] =
            instruction->champion->registers[instruction->args[0] - 1];
    if (instruction->args_type[1] == T_REG)
        instruction->args[1] =
            instruction->champion->registers[instruction->args[1] - 1];
    char one = corewar->memory[instruction->memory_pos +
        (instruction->args[0]) % MEM_SIZE];
    char two = corewar->memory[instruction->memory_pos +
        (instruction->args[0] + 1 % MEM_SIZE)];
    int value = ((one << 8) | two) + instruction->args[1];
    instruction->champion->registers[instruction->args[2] - 1] =
        instruction->memory_pos + value;
    instruction->champion->carry =
        instruction->champion->registers[instruction->args[2] - 1] == 0;
    return 0;
}
