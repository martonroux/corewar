/*
** EPITECH PROJECT, 2023
** COREWAR
** File description:
** write_funcs.c
*/

#include <stdio.h>
#include "my.h"
#include "parser.h"

void write_name(asm_t *parse, FILE *file)
{
    header_t header = parse->header;
    header.magic = COREWAR_EXEC_MAGIC;
    header.magic = REV(header.magic);
    header.prog_size = rev_endian32(parse->header.prog_size);
    fwrite(&header, sizeof(header), 1, file);
}

void write_4bytes(int nb, FILE *file)
{
    int32_t rev = rev_endian32((int32_t)nb);

    fwrite(&rev, 4, 1, file);
}

void write_2bytes(int nb, FILE *file)
{
    int16_t rev = rev_endian16((int16_t)nb);

    fwrite(&rev, 2, 1, file);
}

void write_dir(int nb, int bytes, FILE *file)
{
    if (bytes == 32)
        write_4bytes(nb, file);
    else
        write_2bytes(nb, file);
}
