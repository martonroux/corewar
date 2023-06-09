/*
** EPITECH PROJECT, 2023
** builder
** File description:
** file for builder functions
*/

#include <stdlib.h>
#include "cw_arguments.h"

corewar_arguments_t *create_arguments(void)
{
    corewar_arguments_t *args = malloc(sizeof(corewar_arguments_t));

    *args = (corewar_arguments_t) {0};
    args->dump = -1;
    for (int i = 0; i < 4; i++)
        args->load_address[i] = -1;
    return args;
}

void destroy_arguments(corewar_arguments_t *args)
{
    for (int i = 0; i < args->nb_champions; i++)
        if (args->champions[i])
            fclose(args->champions[i]);
    free(args);
}
