/*
** EPITECH PROJECT, 2023
** writer
** File description:
** file for writer functions
*/

#include <unistd.h>
#include <stdio.h>
#include "my.h"
#include "parser.h"

void write_params(asm_instruction_t *instruction, FILE *file)
{
    int nb = 0;

    for (int i = 0; i < instruction->nb_args; i++) {
        nb = instruction->args[i];
        if (instruction->real_type[i] == T_DIR) {
            write_dir(nb, instruction->direct_size, file);
        }
        if (instruction->real_type[i] == T_IND ||
            instruction->real_type[i] == T_LAB) {
            write_2bytes(nb, file);
        }
        if (instruction->real_type[i] == T_REG)
            fwrite(&instruction->args[i], 1, 1, file);
    }
}

void write_parser(asm_t *parser, char *filename)
{
    FILE *file = NULL;
    char *new = filename;

    new = create_filename(filename);
    file = fopen(new, "w");
    write_name(parser, file);
    for (node_t *node = parser->instructions->head; node; node = node->next) {
        asm_instruction_t *instruction = node->data;
        fwrite(&instruction->code, sizeof(char), 1, file);
        if (instruction->code != 1 && instruction->code != 9 &&
        instruction->code != 12 && instruction->code != 15) {
            write_args(instruction, file);
        }
        write_params(instruction, file);
    }
    free(new);
    fclose(file);
}
