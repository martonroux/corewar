/*
** EPITECH PROJECT, 2023
** instructions
** File description:
** file for instructions functions
*/

#include "corewar.h"
#include "transform.h"
#include "my.h"
#include "champions.h"

instruction_t *create_instruction(char instruction, int memory_pos)
{
    instruction_t *instr = malloc(sizeof(instruction_t));
    op_t op = get_op_tab()[(int) instruction - 1];

    *instr = (instruction_t) {0};
    instr->instruction = instruction;
    instr->memory_pos = memory_pos;
    instr->cycles = op.nbr_cycles;
    for (int i = 0; i < 4; i++) {
        instr->args[i] = 0;
        instr->args_type[i] = 0;
    }
    return instr;
}

instruction_t *copy_instruction(instruction_t *instruction)
{
    instruction_t *copy = malloc(sizeof(instruction_t));

    *copy = *instruction;
    copy->champion = create_champion(instruction->champion->header);
    copy->champion->id = instruction->champion->id;
    copy->champion->carry = instruction->champion->carry;
    my_memcpy(copy->champion->registers, instruction->champion->registers,
            sizeof(uint32_t) * REG_NUMBER);
    return copy;
}
