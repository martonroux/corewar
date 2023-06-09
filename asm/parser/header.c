/*
** EPITECH PROJECT, 2023
** header
** File description:
** file for header functions
*/

#include "parser.h"
#include "my.h"
#include "op.h"

void parse_header_line(char **array, int line_nb, asm_t *parser)
{
    if (line_nb == 0 && !my_strcmp(array[0], NAME_CMD_STRING))
        my_strcpy(parser->header.prog_name, array[1]);
    if (line_nb == 1 && !my_strcmp(array[0], COMMENT_CMD_STRING)) {
        my_strcpy(parser->header.comment, array[1]);
        if (parser->header.comment[0] == 0)
            parser->header.comment[0] = '\1';
    }
    if (line_nb < 2) return;
    for (int i = 0; array[0] && array[0][i]; i++) {
        if (array[0][i] == LABEL_CHAR) {
            list_append(parser->labels, build_label(array[0], line_nb));
            array[0][i] = 0;
            array[0] = LABEL_PTR;
        }
        if (array[0] == LABEL_PTR || !my_strchr(LABEL_CHARS, array[0][i]))
            return;
    }
}

char ***parse_header(FILE *file, asm_t *parser)
{
    char ***array = malloc(sizeof(char **) * 1);
    char *line = NULL;
    char **dup = NULL;
    size_t len = 0;
    int line_nb = 0;

    while (getline(&line, &len, file) != -1) {
        dup = clean_line(line);
        if (!dup)
            continue;
        parse_header_line(dup, line_nb, parser);
        array = realloc(array, sizeof(char **) * (line_nb + 2));
        if (!array)
            print_error("Can't realloc\n");
        array[line_nb++] = dup;
        array[line_nb] = NULL;
    }
    check_header_parse(array, parser);
    free(line);
    return array;
}
