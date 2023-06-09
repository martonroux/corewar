/*
** EPITECH PROJECT, 2023
** COREWAR
** File description:
** arguments_error.c
*/

#include "my.h"
#include "op.h"
#include <stdio.h>
#include <stdlib.h>

void get_argument_error(char *instruction, char *conflict,
                            int types, int conf_type)
{
    char *type = "";
    char *await = "";

    if (conf_type == T_REG) type = my_strcat(type, "REGISTER");
    if (conf_type == T_DIR) type = my_strcat(type, "DIRECT");
    if (conf_type == T_IND) type = my_strcat(type, "INDIRECT");
    if (conf_type == -1) type = my_strcat(type, "UNDEFINED");

    if ((T_REG & types) == T_REG)
        await = my_strcat(await, " REGISTER");
    if ((T_IND & types) == T_IND)
        await = my_strcat(await, " INDIRECT");
    if ((T_DIR & types) == T_DIR)
        await = my_strcat(await, " DIRECT");
    print_error("Error on instruction: %s, argument: [%s] has type: %s, but"
                    " awaited [%s ].\n", instruction, conflict, type, await);
}

void wrong_nb_args_error(int j, int nb_args, char *inst)
{
    if (j != nb_args) {
        if (j < nb_args)
            print_error("Not enough arguments on instruction: [%s]\n", inst);
        else
            print_error("Too much arguments on instruction: [%s]\n", inst);
    }
}
