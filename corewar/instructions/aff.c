/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-corewar-louis.rollet
** File description:
** aff
*/

#include "corewar.h"

int instruction_aff(corewar_t *corewar, instruction_t *instruction)
{
    uint32_t v;

    (void) corewar;
    if (instruction->args[0] < 0 || instruction->args[0] >= 16)
        return 0;
    v = instruction->champion->registers[instruction->args[0] - 1] % 256;
    write(1, &v, 1);
    return 0;
}
