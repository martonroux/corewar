/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-corewar-louis.rollet [WSL: Ubuntu]
** File description:
** my_strcat
*/

#include "my.h"
#include <stdlib.h>

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;
    char *new = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));

    for (; dest[i]; i++)
        new[i] = dest[i];
    for (; src[j]; j++)
        new[i + j] = src[j];
    new[i + j] = '\0';
    return new;
}
