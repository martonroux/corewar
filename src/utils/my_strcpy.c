/*
** EPITECH PROJECT, 2023
** my_strcpy
** File description:
** file for my strcpy functions
*/

#include "my.h"

void my_strcpy(char *dest, char *src)
{
    int i = 0;

    for (; src[i]; i++)
        dest[i] = src[i];
    dest[i] = 0;
}
