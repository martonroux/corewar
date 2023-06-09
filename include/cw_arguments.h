/*
** EPITECH PROJECT, 2023
** cw_arguments
** File description:
** file for cw arguments functions
*/

#ifndef CW_ARGUMENTS_H
    #define CW_ARGUMENTS_H

    #include <stdio.h>
    #include <stdbool.h>

typedef struct corewar_arguments_s {
    int dump;
    int nb_champions;
    FILE *champions[4];
    int load_address[4];
    bool debug;
} corewar_arguments_t;

corewar_arguments_t *get_corewar_arguments(int ac, char **av);
corewar_arguments_t *create_arguments(void);
void destroy_arguments(corewar_arguments_t *args);

void handle_dump_arg(corewar_arguments_t *args, char *arg);
void handle_new_champ_arg(corewar_arguments_t *args, char *str, int *champion);
void handle_address_arg(corewar_arguments_t *args, char *str, int champion);
void handle_champion_file_arg(corewar_arguments_t *args, char *str, int *champ);
void handle_help_arg(void);

#endif
