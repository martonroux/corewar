/*
** EPITECH PROJECT, 2023
** COREWAR
** File description:
** read_next_bytes.c
*/

#include <stdint.h>
#include <stdbool.h>

bool check_ff_ff(const char *memory, int bytes)
{
    int found = 0;

    if (bytes != 4)
        return false;
    if (memory[0] == (char)0xFF)
        found++;
    if (memory[1] == (char)0xFF)
        found++;
    if (memory[2] == (char)0x01)
        found++;
    if (memory[3] == (char)0x00)
        found++;
    return found == 4;
}

int read_next_bytes(const char *memory, int bytes)
{
    int32_t value = 0;

    if (check_ff_ff(memory, bytes) == true)
        return -65280;
    for (int i = 0; i < bytes; i++) {
        value = (value << 8) | ((uint8_t)memory[i] & 0xFF);
    }
    if (value & (1 << ((bytes * 8) - 1))) {
        value |= ~((1 << (bytes * 8)) - 1);
    }
    return value;
}
