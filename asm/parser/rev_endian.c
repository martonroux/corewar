/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-corewar-louis.rollet [WSL: Ubuntu]
** File description:
** rev_endian
*/

#include <stdint.h>

int16_t rev_endian16(int16_t nb)
{
    uint16_t unsigned_num = (uint16_t)nb;

    unsigned_num = (unsigned_num >> 8) | (unsigned_num << 8);
    return (int16_t)unsigned_num;
}

int32_t rev_endian32(int32_t num)
{
    uint32_t unsigned_num = num;

    unsigned_num = ((unsigned_num << 8) & 0xFF00FF00) |
            ((unsigned_num >> 8) & 0x00FF00FF);
    return (int32_t)((unsigned_num << 16) | (unsigned_num >> 16));
}
