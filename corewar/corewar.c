/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** file for corewar functions
*/

#include <stdlib.h>
#include "corewar.h"
#include "champions.h"
#include "my.h"

corewar_t *create_corewar(int ac, char **av)
{
    corewar_t *corewar = malloc(sizeof(corewar_t));

    my_memset(corewar, 0, sizeof(corewar_t));
    corewar->args = get_corewar_arguments(ac, av);
    corewar->instructions = create_list();
    corewar->instr_to_add = create_list();
    corewar->champions = create_list();
    corewar->cycle_to_die = CYCLE_TO_DIE;
    corewar->last_live = -1;
    load_champions(corewar);
    return corewar;
}

void destroy_corewar(corewar_t *corewar)
{
    list_free(corewar->champions, false);
    list_free(corewar->instructions, true);
    list_free(corewar->instr_to_add, true);
    free(corewar);
}
