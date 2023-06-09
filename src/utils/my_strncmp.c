/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-corewar-louis.rollet
** File description:
** my_strncmp
*/

#include "my.h"

int my_strncmp(char *str, char *str2, int n)
{
    int i = 0;

    for (; str[i] && str2[i] && i < n - 1; i++) {
        if (str[i] != str2[i])
            return str[i] - str2[i];
    }
    return str[i] - str2[i];
}
