/*
** EPITECH PROJECT, 2023
** my_putnbr
** File description:
** file for my putnbr functions
*/

#include <unistd.h>
#include "my.h"

void my_putnberr(int nb)
{
    char c = ABS(nb) % 10 + '0';

    if (nb < 0) {
        write(2, "-", 1);
        nb *= -1;
    }
    if (nb >= 10) {
        nb /= 10;
        my_putnberr(nb);
        write(2, &c, 1);
    } else
        write(2, &c, 1);
}
