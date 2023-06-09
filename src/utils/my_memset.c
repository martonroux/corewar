/*
** EPITECH PROJECT, 2023
** my_memset
** File description:
** file for my memset functions
*/

#include "my.h"

void my_memset(void *ptr, char value, int size)
{
    char *tmp = ptr;

    for (int i = 0; i < size; i++)
        tmp[i] = value;
}
