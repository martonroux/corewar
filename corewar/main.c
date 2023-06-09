/*
** EPITECH PROJECT, 2023
** main
** File description:
** file for main functions
*/

#include "corewar.h"

int main(int ac, char **av)
{
    corewar_t *corewar = create_corewar(ac, av);

    run_loop(corewar);
    destroy_corewar(corewar);
    return 0;
}
