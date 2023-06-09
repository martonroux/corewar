/*
** EPITECH PROJECT, 2023
** main
** File description:
** file for main functions
*/

#include "parser.h"
#include "my.h"
#include "asm.h"

int main(int ac, char **av)
{
    if (ac != 2)
        print_error("Usage: ./asm file_name[.s]\n");
    if (!my_strcmp(av[1], "-h"))
        return asm_h_flag();
    parse_file(av[1]);
    return 0;
}
