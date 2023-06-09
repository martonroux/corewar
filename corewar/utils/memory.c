/*
** EPITECH PROJECT, 2023
** memory
** File description:
** file for memory functions
*/

#include "my.h"
#include "corewar.h"

static void print_padding(int i, int log)
{
    for (int j = 0; j < 4 - log - (i == 0); j++)
        print(" ");
}

void print_memory(corewar_t *corewar)
{
    char str[17] = "0123456789ABCDEF";
    int log;

    for (int i = 0; i < MEM_SIZE; i++) {
        if (i % 32 == 0) {
            log = my_log(i, 16);
            print("%x", i);
            print_padding(i, log);
            print(" : ");
        }
        print("%c%c ", str[(corewar->memory[i] >> 4) & 0xF],
            str[corewar->memory[i] & 0xF]);
        if (i % 32 == 31)
            my_putchar('\n', 1);
    }
}
