/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-corewar-louis.rollet
** File description:
** my_strndup
*/

#include <stdlib.h>
#include "my.h"

char *my_strndup(char *str, int n)
{
    char *dup = malloc(sizeof(char) * (n + 1));
    int i = 0;

    for (; str[i] && i < n; i++)
        dup[i] = str[i];
    dup[i] = 0;
    return dup;
}
