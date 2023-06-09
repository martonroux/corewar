/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-corewar-louis.rollet [WSL: Ubuntu]
** File description:
** my_strcmp
*/

#include <stdlib.h>
#include "my.h"

int my_strcmp(char *str, char *str2)
{
    int i = 0;

    if (str == NULL || str2 == NULL)
        return 1;
    for (; str[i] != '\0' && str2[i] != '\0'; i++)
        if (str[i] != str2[i])
            return 1;
    if (str[i] != str2[i])
        return 1;
    return 0;
}
