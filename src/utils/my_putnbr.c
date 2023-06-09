/*
** EPITECH PROJECT, 2023
** my_putnbr
** File description:
** file for my putnbr functions
*/

#include <unistd.h>
#include "my.h"

void my_putnbr(int nb)
{
    char c = ABS(nb) % 10 + '0';

    if (nb < 0) {
        write(1, "-", 1);
        nb *= -1;
    }
    if (nb >= 10) {
        nb /= 10;
        my_putnbr(nb);
        write(1, &c, 1);
    } else
        write(1, &c, 1);
}
