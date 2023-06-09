/*
** EPITECH PROJECT, 2023
** my_strchr
** File description:
** file for my strchr functions
*/

#include <stdlib.h>
#include "my.h"

char *my_strchr(char *str, char c)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            return str + i;
    return NULL;
}
