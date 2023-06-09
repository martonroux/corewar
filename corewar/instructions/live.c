/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-corewar-louis.rollet
** File description:
** live
*/

#include "corewar.h"
#include "my.h"

int instruction_live(corewar_t *corewar, instruction_t *instruction)
{
    int id = instruction->args[0];
    if (id < 0 || id >= 4 || corewar->headers[id] == NULL)
        return 84;
    corewar->lives[id]++;
    corewar->last_live = id;
    corewar->total_lives++;
    if (!corewar->args->debug)
        print("Le joueur %d (%s) est en vie.\n", id + 1,
            corewar->headers[id]->prog_name);
    return 0;
}
