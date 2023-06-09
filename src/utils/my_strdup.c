/*
** EPITECH PROJECT, 2023
** my_strdup
** File description:
** file for my strdup functions
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char *str)
{
    char *dup = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i = 0;

    for (; str[i]; i++)
        dup[i] = str[i];
    dup[i] = 0;
    return dup;
}
