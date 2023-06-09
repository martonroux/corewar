/*
** EPITECH PROJECT, 2023
** COREWAR
** File description:
** is_alpha_num.c
*/

#include "my.h"
#include <stdbool.h>
#include <stdio.h>

bool is_alpha(char const *str)
{
    for (int i = 0; str[i]; i++) {
        if (!my_strchr(
                "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ",
                    str[i]))
            return false;
    }
    return true;
}

bool is_num(char const *str)
{
    int i = 0;

    if (str[0] == '-')
        i++;
    for (; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return false;
        }
    }
    return true;
}

bool is_alpha_num(char const *str)
{
    for (int i = 0; str[i]; i++) {
        if (!my_strchr(
            "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ",
            str[i]) && !my_strchr("0123456789", str[i]))
            return false;
    }
    return true;
}

int is_alpha_numeric(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    if ((c >= 'a' && c <= 'z') || c == '_')
        return 2;
    if (c >= 'A' && c <= 'Z')
        return 3;
    return 0;
}
