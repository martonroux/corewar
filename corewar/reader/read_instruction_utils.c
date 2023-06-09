/*
** EPITECH PROJECT, 2023
** COREWAR
** File description:
** read_instruction_utils.c
*/

#include "corewar.h"
#include "transform.h"
#include "my.h"

int get_size(args_type_t args_type, char instruction_code)
{
    switch (args_type) {
        case T_REG:
            return 1;
        case T_IND:
            return IND_SIZE;
        case T_DIR:
            return DIR_SIZE(get_op_tab()[(int)
                instruction_code - 1].direct_size);
        default:
            return 0;
    }
}

void get_instruction_args(corewar_t *corewar, instruction_t *instruction)
{
    char instruction_code = instruction->instruction;
    int *args_type = instruction->args_type;
    int offset = (get_op_tab()[(int)instruction_code - 1].pcb == true) ? 2 : 1;
    int bytes;

    for (int i = 0; i < 4; i++)
        instruction->args[i] = 0;
    for (int i = 0; i < 4 && args_type[i] != 0; i++) {
        bytes = get_size((char) args_type[i], instruction_code);
        instruction->args[i] = read_next_bytes(corewar->memory +
                (instruction->memory_pos + offset), bytes);
        offset += bytes;
    }
}

int get_instruction_size(char code, instruction_t *instruction)
{
    int size = 1;
    int dir_size = DIR_SIZE(get_op_tab()[(int) code - 1].direct_size);

    if (get_op_tab()[(int) code - 1].pcb == true)
        size++;
    for (int i = 0; i < 4 && instruction->args_type[i] != 0; i++) {
        if (instruction->args_type[i] == T_REG)
            size += REG_SIZE;
        if (instruction->args_type[i] == T_IND)
            size += IND_SIZE;
        if (instruction->args_type[i] == T_DIR)
            size += dir_size;
    }
    return size;
}

void get_instruction_arg_type(corewar_t *corewar, instruction_t *instruction)
{
    int mem_pos = instruction->memory_pos;
    char instruction_code = corewar->memory[mem_pos];

    if (get_op_tab()[(int) instruction_code - 1].pcb == true) {
        my_intcpy(instruction->args_type,
                    read_instruction_type_pcb(corewar->memory[mem_pos + 1]),
                        4);
    } else {
        my_intcpy(instruction->args_type,
                    read_instruction_type_nopcb(), 4);
    }
}
