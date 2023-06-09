/*
** EPITECH PROJECT, 2023
** my_putnbr_base
** File description:
** file for my putnbr base functions
*/

#include "my.h"

void my_putnbr_base(int nbr, char const *base)
{
    int base_len = my_strlen(base);
    int nb = nbr;

    if (nbr < 0) {
        my_putchar('-', 1);
        nb = -nbr;
    }
    if (nb >= base_len)
        my_putnbr_base(nb / base_len, base);
    my_putchar(base[nb % base_len], 1);
}
