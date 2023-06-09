/*
** EPITECH PROJECT, 2023
** parser
** File description:
** file for parser functions
*/

#ifndef PARSER_H
    #define PARSER_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include "asm.h"
    #include <unistd.h>
    #include <fcntl.h>
    #include "my.h"
    #include <sys/types.h>
    #include <stdlib.h>

asm_t *parse_file(char *filename);
char **clean_line(char *line);
char ***parse_header(FILE *file, asm_t *parser);
void parse_body_line(char **array, int line_nb, asm_t *parser);
void write_parser(asm_t *parser, char *filename);
int check_header_parse(char ***str, asm_t *parser);

#endif
