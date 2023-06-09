/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** file for my putstr functions
*/

#include <unistd.h>
#include "my.h"

void my_putsterr(char *str)
{
    write(2, str, my_strlen(str));
}
