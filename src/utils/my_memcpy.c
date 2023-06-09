/*
** EPITECH PROJECT, 2023
** my_memcpy
** File description:
** file for my memcpy functions
*/

#include "my.h"

void *my_memcpy(void *dest, const void *src, size_t n)
{
    char *dest_c = dest;
    const char *src_c = src;

    for (size_t i = 0; i < n; i++)
        dest_c[i] = src_c[i];
    return dest;
}
