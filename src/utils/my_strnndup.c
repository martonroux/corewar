/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-corewar-louis.rollet
** File description:
** my_strnndup
*/

#include "my.h"
#include <stdlib.h>

char *my_strnndup(char *str, int a, int b)
{
    char *dup = malloc(sizeof(char) * (b - a + 1));
    int i = 0;

    for (; str[a] && a < b; a++, i++)
        dup[i] = str[a];
    dup[i] = 0;
    return dup;
}
