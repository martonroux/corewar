/*
** EPITECH PROJECT, 2023
** impl
** File description:
** file for impl functions
*/

#include "cw_arguments.h"
#include "my.h"
#include "op.h"
#include <unistd.h>
#include <stdio.h>

void handle_dump_arg(corewar_arguments_t *args, char *arg)
{
    args->dump = my_getnbr_base(arg, "0123456789ABCDEF");
    if (args->dump < 0)
        print_error("Invalid dump argument\n");
}

void handle_new_champ_arg(corewar_arguments_t *args, char *str, int *champion)
{
    int champ = my_getnbr(str);

    if (champ < 1 || champ > 4)
        print_error("Invalid champion number %d\n", champ);
    if (args->champions[champ - 1])
        print_error("Champion number %d already taken\n", champ);
    *champion = champ;
}

void handle_address_arg(corewar_arguments_t *args, char *str, int champion)
{
    int address = my_getnbr(str);

    if (args->load_address[champion - 1] != -1)
        print_error("Address for the champion %d already set\n", champion);
    args->load_address[champion - 1] = address % MEM_SIZE;
}

void handle_help_arg(void)
{
    write(1, "USAGE\n"
    "./corewar [-dump nbr_cycle] [[-n prog_number] [-a load_address] prog_name]"
    " ...\n"
    "DESCRIPTION\n"
    "-dump nbr_cycle dumps the memory after the nbr_cycle execution (if the "
    "round isn’t\n"
    "already over) with the following format: 32 bytes/line\n"
    "in hexadecimal (A0BCDEFE1DD3...)\n"
    "-n prog_number sets the next program’s number. By default, the first free"
    " number\n"
    "in the parameter order\n"
    "-a load_address sets the next program’s loading address. When no address"
    " is\n"
    "specified, optimize the addresses so that the processes are as far\n"
    "away from each other as possible. The addresses are MEM_SIZE modulo.\n",
    591);
}

void handle_champion_file_arg(corewar_arguments_t *args, char *str, int *champ)
{
    FILE *file = fopen(str, "r");

    if (!file)
        print_error("Invalid champion file: %s\n", str);
    if (args->champions[*champ - 1] != NULL)
        print_error("Champion number %d already taken\n", *champ);
    args->champions[*champ - 1] = file;
    args->nb_champions++;
    (*champ)++;
}
