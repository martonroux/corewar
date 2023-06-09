/*
** EPITECH PROJECT, 2023
** champions
** File description:
** file for champions functions
*/

#ifndef CHAMPIONS_H
    #define CHAMPIONS_H

    #include <stdlib.h>
    #include "corewar.h"
    #include "op.h"

champion_t *create_champion(header_t *header);
void load_champions(corewar_t *corewar);

#endif
