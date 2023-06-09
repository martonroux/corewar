/*
** EPITECH PROJECT, 2023
** my_getnbr_base
** File description:
** file for my getnbr base functions
*/

#include <stddef.h>
#include "my.h"

int my_getnbr_base(char *str, char *base)
{
    int nb = 0;
    int neg = 1;
    int base_len = my_strlen(base);
    char *index;

    if (!str || !str[0])
        print_error("Invalid number\n");
    if (str[0] == '-')
        neg = -1;
    for (int i = neg == -1; str[i]; i++) {
        index = my_strchr(base, str[i]);
        if (!index)
            print_error("Invalid number character %c in %s\n", str[i], str);
        nb = nb * base_len + (int)(long) (index - base);
    }
    return nb * neg;
}
