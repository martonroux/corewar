/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** file for my putstr functions
*/

#include <unistd.h>
#include "my.h"

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}
