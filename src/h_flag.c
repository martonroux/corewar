/*
** EPITECH PROJECT, 2023
** COREWAR
** File description:
** h_flag.c
*/

#include <unistd.h>
#include "my.h"

int asm_h_flag(void)
{
    char *text = "USAGE\n"
                    "./asm file_name[.s]\n"
                    "DESCRIPTION\n"
                    "file_name file in assembly language to be "
                    "converted into file_name.cor, an\n"
                    "executable in the Virtual Machine.\n";

    write(1, text, my_strlen(text));
    return 0;
}
