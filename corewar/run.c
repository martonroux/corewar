/*
** EPITECH PROJECT, 2023
** run
** File description:
** file for run functions
*/

#include "corewar.h"

void loop_exec_instructions(corewar_t *corewar)
{
    instruction_t *instruction = NULL;

    for (node_t *node = corewar->instructions->tail; node; node = node->prev) {
        instruction = (instruction_t *) node->data;
        if (instruction == NULL || instruction->cycles-- > 1)
            continue;
        exec_instruction(corewar, instruction);
    }
}

/* BREAK MAIN WHILE LOOP BY RETURNING -1 */
int run_corewar(corewar_t *corewar, int *checks)
{
    corewar->cycle++;
    build_instr_to_add(corewar);
    if (corewar->cycle % corewar->cycle_to_die == 0) {
        corewar->cycle_to_die -=
            50 * (corewar->total_lives >= 21 || (*checks)++ >= 10);
        kill_instructions(corewar);
    }
    loop_exec_instructions(corewar);
    return 0;
}
