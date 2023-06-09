/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-corewar-louis.rollet [WSL: Ubuntu]
** File description:
** write_type_arg
*/

#include "op.h"
#include "my.h"
#include "parser.h"

void add_octet(int *octet, int position, int number)
{
    int pos = position * 2;
    octet[pos] = number / 10;
    octet[pos + 1] = number % 10;
}

char to_decimal(int *octet)
{
    unsigned char result = 0;
    for (int i = 0; i < 8; i++) {
        result = (result << 1) + octet[i];
    }
    return result;
}

void write_args(asm_instruction_t *instruction, FILE *file)
{
    int *octet = malloc(sizeof(int) * 8);
    unsigned char c = 0;
    int i = 0;

    for (int i = 0; i < 8; i++)
        octet[i] = 0;

    for (i = 0; i < instruction->nb_args; i++)  {
        if (instruction->real_type[i] == T_DIR ||
            instruction->real_type[i] == T_LAB)
            add_dir(octet, i);
        if (instruction->real_type[i] == T_REG)
            add_reg(octet,i);
        if (instruction->real_type[i] == T_IND)
            add_indir(octet, i);
    }
    c = to_decimal(octet);
    fwrite(&c, sizeof(char), 1, file);
}
