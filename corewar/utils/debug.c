/*
** EPITECH PROJECT, 2023
** COREWAR
** File description:
** debug.c
*/

// TEMPORARY FILE: NOT NECESSARY ONCE PROJET FINISHED

#include "my.h"
#include "corewar.h"
#include "transform.h"

void debug_print_instruction(instruction_t *instruction, corewar_t *corewar)
{
    char instruction_code = instruction->instruction;

    print_debug("PID: %d, INSTRUCTION: %s, ARGS TYPE: ",
                    instruction->pid,
                    get_op_tab()[(int) instruction_code - 1].mnemonique);
    for (int i = 0; i < 4; i++)
        print_debug("%d ", instruction->args_type[i]);
    print_debug(", ARGS VAL: ");
    for (int i = 0; i < 4; i++)
        print_debug("%d ", instruction->args[i]);
    print_debug(", SIZE: %d, MEM_POS: %d, CYCLES: %d, CURRENT CYCLE: %d\n",
        instruction->size, instruction->memory_pos,
            instruction->cycles, corewar->cycle);
}
