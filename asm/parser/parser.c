/*
** EPITECH PROJECT, 2023
** parser
** File description:
** file for parser functions
*/

#include <stdio.h>
#include "my.h"
#include "parser.h"
#include "op.h"
#include "asm.h"

asm_t *parse_file(char *filename)
{
    FILE *file = fopen(filename, "r");
    asm_t *parser = build_asm();
    char ***array = NULL;

    if (!file)
        print_error2("Can't open file\n");
    array = parse_header(file, parser);
    fclose(file);
    if (!array)
        print_error2("Can't parse header\n");
    check_labels(array, parser);
    verif_argument(array);
    for (int i = 0; array[i]; i++)
        parse_body_line(array[i], i, parser);
    create_bytes(parser);
    set_instruction_values(parser);
    write_parser(parser, filename);
    destroy_all(parser, array);
    return parser;
}
