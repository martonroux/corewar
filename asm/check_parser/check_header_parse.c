/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-corewar-louis.rollet [WSL: Ubuntu]
** File description:
** check_header_parse
*/

#include "parser.h"
#include "asm.h"
#include "my.h"

int check_header_parse(char ***str, asm_t *parser)
{
    header_t header = parser->header;
    (void)str;
    if (header.prog_name[0] == 0)
        print_error("check_header_parse.c : null name\n");
    if (header.comment[0] == 0)
        print_error("check_header_parse.c : null comment\n");
    if (header.prog_name[128] != '\0')
        print_error(
        "check_header_parse.c : name must be less than 129 characters");
    if (header.comment[2048] != '\0')
        print_error(
        "check_header_parse.c : comment must be less than 2049 characters");
    return 0;
}
