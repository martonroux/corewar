/*
** EPITECH PROJECT, 2023
** COREWAR
** File description:
** pcb.c
*/

#include "op.h"

int get_pcb(args_type_t const real_type[MAX_ARGS_NUMBER])
{
    char bytes[8] = "00000000";
    int increment = 1;
    int value = 0;

    for (int i = 0; i < MAX_ARGS_NUMBER; i++) {
        if (real_type[i] == 1)
            bytes[i * 2 + 1] = '1';
        if (real_type[i] == 2)
            bytes[i * 2] = '1';
        if (real_type[i] == 3) {
            bytes[i * 2] = '1';
            bytes[i * 2 + 1] = '1';
        }
    }
    for (int i = 7; i >= 0; i--) {
        if (bytes[i] == '1')
            value += increment;
        increment *= 2;
    }
    return value;
}
