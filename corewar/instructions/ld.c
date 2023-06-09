/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-corewar-louis.rollet
** File description:
** ld
*/

#include "corewar.h"

int instruction_ld(corewar_t *corewar, instruction_t *instruction)
{
    (void)corewar;
    if (instruction->args_type[1] != T_REG ||
    !check_instruction_args(instruction))
        return 1;
    if (instruction->args_type[0] == T_DIR) {
        instruction->champion->registers[instruction->args[1] - 1] =
            instruction->args[0];
    } else {
        int pc = instruction->memory_pos + (instruction->args[0] % IDX_MOD)
                % MEM_SIZE;
        instruction->champion->registers[instruction->args[1] - 1] =
                corewar->memory[pc >= 0 ? pc : MEM_SIZE + pc];
    }
    instruction->champion->carry =
        instruction->champion->registers[instruction->args[1] - 1] == 0;
    return 0;
}
