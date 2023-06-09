/*
** EPITECH PROJECT, 2023
** arguments_handler
** File description:
** file for arguments handler functions
*/

#include "cw_arguments.h"
#include "my.h"
#include <stdlib.h>
#include <stdio.h>

corewar_arguments_t *get_corewar_arguments(int ac, char **av)
{
    corewar_arguments_t *args = create_arguments();
    int next_champ = 1;

    for (int i = 1; i < ac; i++) {
        if (av[i][0] == '-' && !(av[i][1] == 'h' || av[i][1] == 'd')
            && i + 1 >= ac) {
            print_error("Invalid argument %s\n", av[i]); continue;
        } if (!my_strcmp(av[i], "-dump")) {
            handle_dump_arg(args, av[++i]); continue;
        } if (!my_strcmp(av[i], "-n")) {
            handle_new_champ_arg(args, av[++i], &next_champ); continue;
        } if (!my_strcmp(av[i], "-a")) {
            handle_address_arg(args, av[++i], next_champ); continue;
        } if (!my_strcmp(av[i], "-h")) {
            handle_help_arg(); exit(0);
        } if (!my_strcmp(av[i], "-d")) {
            args->debug = true; continue;
        } handle_champion_file_arg(args, av[i], &next_champ);
    }
    return args;
}
