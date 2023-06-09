/*
** EPITECH PROJECT, 2023
** my_log
** File description:
** file for my log functions
*/

#include "my.h"

int my_log(int nb, int base)
{
    int i = 0;

    for (; nb > 0; i++)
        nb /= base;
    return i;
}
