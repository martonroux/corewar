/*
** EPITECH PROJECT, 2023
** COREWAR
** File description:
** check_instruction.c
*/

#include <stdbool.h>
#include "corewar.h"
#include "transform.h"
#include "my.h"

bool check_instruction_args(instruction_t *instruction)
{
    char code = instruction->instruction;
    int args_type[4] = {0};
    op_t op = get_op_tab()[(int) code - 1];

    my_intcpy(args_type, instruction->args_type, 4);
    for (int i = 0; i < op.nbr_args; i++) {
        if (args_type[i] == 0 || (args_type[i] & op.type[i]) == 0) {
            return false;
        }
    }
    return true;
}

bool check_instruction_args_reg(instruction_t *instruction)
{
    for (int i = 0; i <
            get_op_tab()[(int) instruction->instruction - 1].nbr_args; i++) {
        if ((instruction->args_type[i] == T_REG && (instruction->args[i] < 1
            || instruction->args[i] > REG_NUMBER)))
            return false;
    }
    return true;
}
