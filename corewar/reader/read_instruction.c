/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-corewar-louis.rollet [WSL: Ubuntu]
** File description:
** read_instruction
*/

#include "../../include/my.h"
#include "op.h"
#include "corewar.h"
#include "transform.h"

int *read_instruction_type_nopcb(void)
{
    int *result = malloc(sizeof(int) * 4);

    result[0] = T_DIR;
    return result;
}

int *read_instruction_type_pcb(int nb)
{
    unsigned int mask = 1 << (sizeof(nb) * 8 - 1);
    int instruction[8] = {0};
    int array[4] = {0};
    int *result = malloc(sizeof(int) * 4);

    for (int i = 0; i < (int) sizeof(nb) * 8 - 8; i++)
        mask >>= 1;
    for (int i = 0; i < 8; i++) {
        instruction[i] = (nb & mask) ? 1 : 0;
        mask >>= 1;
    }
    for (int i = 0; i < 8; i += 2)
        array[i / 2] = instruction[i] * 10 + instruction[i + 1];
    for (int i = 0; i < 4; i++) {
        if (array[i] == 0) result[i] = 0;
        if (array[i] == 10) result[i] = T_DIR;
        if (array[i] == 11) result[i] = T_IND;
        if (array[i] == 1) result[i] = T_REG;
    }
    return result;
}

void update_instr_args(corewar_t *corewar, instruction_t *instruction)
{
    get_instruction_args(corewar, instruction);
    if (check_instruction_args_reg(instruction) == false) {
        instruction->instruction = 0;
        return;
    }
}

void first_read_instruction(corewar_t *corewar, instruction_t *instruction)
{
    int mem_pos = instruction->memory_pos;
    char instruction_code = corewar->memory[mem_pos];
    instruction->instruction = instruction_code;
    if (instruction_code <= 0x00 || instruction_code > 0x10) {
        instruction->instruction = 0;
        return;
    }
    int cycles = get_op_tab()[(int) instruction_code - 1].nbr_cycles;
    get_instruction_arg_type(corewar, instruction);
    if (check_instruction_args(instruction) == false) {
        instruction->instruction = 0;
        return;
    }
    instruction->cycles = cycles;
    instruction->size = get_instruction_size(instruction_code, instruction);
    get_instruction_args(corewar, instruction);
    if (check_instruction_args_reg(instruction) == false) {
        instruction->instruction = 0;
        return;
    }
}
