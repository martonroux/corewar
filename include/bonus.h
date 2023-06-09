/*
** EPITECH PROJECT, 2023
** COREWAR
** File description:
** bonus.h
*/

#ifndef COREWAR_BONUS_H
    #define COREWAR_BONUS_H

typedef struct corewar_s corewar_t;

/* COREWAR_DEBUGGER BONUS */

void printer(corewar_t *corewar, int max_lines, int max_per_line);
void print_general_data(corewar_t *corewar, int index, int max_per_line);
void print_byte_colors(corewar_t *corewar, int index);

#endif
