/*
** EPITECH PROJECT, 2023
** my_putchar
** File description:
** file for my putchar functions
*/

#include <unistd.h>
#include "my.h"

void my_putchar(char c, int output)
{
    write(output, &c, 1);
}
