/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-corewar-louis.rollet
** File description:
** st
*/

#include "corewar.h"

int instruction_st(corewar_t *corewar, instruction_t *instruction)
{
    int pc;
    int value;

    if (instruction->args_type[0] != T_REG ||
        !check_instruction_args(instruction))
        return 1;
    if (instruction->args_type[1] == T_REG) {
        instruction->champion->registers[instruction->args[1] - 1] =
            instruction->champion->registers[instruction->args[0] - 1];
    } else {
        pc = instruction->memory_pos +
            (instruction->args[1] % IDX_MOD) % MEM_SIZE;
        pc = pc >= 0 ? pc : MEM_SIZE + pc;
        value = instruction->champion->registers[instruction->args[0] - 1];
        write_in_memory(corewar, pc, value, 4);
        for (int i = 0; i < 4; i++)
            corewar->memory_owner[pc + i] =
                (char) (instruction->champion->id + 1);
    }
    return 0;
}
