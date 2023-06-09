/*
** EPITECH PROJECT, 2023
** string
** File description:
** file for string functions
*/

#include "my.h"

int my_strlen(const char *str)
{
    int i = 0;

    for (; str[i]; i++);
    return i;
}
