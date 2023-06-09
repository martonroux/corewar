/*
** EPITECH PROJECT, 2023
** write
** File description:
** file for write functions
*/

#include "corewar.h"

void write_in_memory(corewar_t *corewar, int pc, int value, int bytes)
{
    for (int i = 0; i < bytes; i++) {
        corewar->memory[(pc + i) % MEM_SIZE] =
            (char) ((value >> (8 * (bytes - i - 1))) & 0xFF);
    }
}
