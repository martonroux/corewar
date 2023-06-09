/*
** EPITECH PROJECT, 2023
** my_char_count
** File description:
** file for my char count functions
*/

#include "my.h"

int my_char_count(char *str, char c)
{
    int count = 0;

    for (int i = 0; str[i]; i++, count += (str[i] == c));
    return count;
}
