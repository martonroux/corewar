/*
** EPITECH PROJECT, 2023
** COREWAR
** File description:
** printer.c
*/

#include "corewar.h"
#include "my.h"
#include "bonus.h"

static void print_padding_bonus(int i, int log)
{
    for (int j = 0; j < 4 - log - (i == 0); j++)
        print(" ");
}

void print_memory_bonus(corewar_t *corewar, int max_lines, int max_per_line)
{
    int log;

    for (int i = 0; i < MEM_SIZE && i < 64 * max_lines; i++) {
        if (i % max_per_line == 0) {
            log = my_log(i, 16);
            print("%x", i);
            print_padding_bonus(i, log);
            print(" : ");
        }
        print_byte_colors(corewar, i);
        print_general_data(corewar, i, max_per_line);
        if (i % max_per_line == max_per_line - 1)
            my_putchar('\n', 1);
    }
}

static void my_sleep(void)
{
    __attribute__((unused)) int delay = 0;
    for (int i = 0; i < 10000000; i++) {
        delay++;
        delay *= 2;
        delay /= 2;
    }
}

void printer(corewar_t *corewar, int max_lines, int max_per_line)
{
    print("\x1b[0;0H");
    print_memory_bonus(corewar, max_lines, max_per_line);
    my_sleep();
}
