/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-corewar-louis.rollet [WSL: Ubuntu]
** File description:
** add_args
*/

#include "my.h"

void add_reg(int *octet, int position)
{
    add_octet(octet, position, 1);
}

void add_dir(int *octet, int position)
{
    add_octet(octet, position, 10);
}

void add_indir(int *octet, int position)
{
    add_octet(octet, position, 11);
}
