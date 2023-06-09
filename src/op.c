/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** file to get the op table
*/

#include "op.h"

#include <stdio.h>

op_t *get_op_tab(void)
{
    static op_t    op_tab[] = {{"live", 1, {T_DIR}, 1, 10, 32, false},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, 32, true},
    {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, 32, true},
    {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, 32, true},
    {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, 32, true},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},
        6, 6,32, true},
    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
        7, 6,32, true},
    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
        8, 6,32, true},
    {"zjmp", 1, {T_DIR}, 9, 20, 16, false},
    {"ldi", 3,{T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,16, true},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,16, true},
    {"fork", 1, {T_DIR}, 12, 800, 16, false},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, 32, true},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
        14, 50,16, true}, {"lfork", 1, {T_DIR}, 15, 1000, 16, false},
    {"aff", 1, {T_REG}, 16, 2, 32, true}, {0, 0, {0}, 0, 0, 0, false}};
    return op_tab;
}
