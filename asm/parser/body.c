/*
** EPITECH PROJECT, 2023
** body
** File description:
** file for body functions
*/

#include "parser.h"
#include "transform.h"
#include "my.h"

void parse_body_line(char **array, int line_nb, asm_t *parser)
{
    asm_instruction_t *instruction = NULL;
    args_type_t real_types[MAX_ARGS_NUMBER] = {0};
    op_t *ops = get_op_tab();
    op_t *act_ops;
    int i = 0;

    for (; array[i] == (char *) 1; i++);
    if (!array[i] || !array[i][0] || array[i][0] == '.')
        return;
    for (int j = 0; array[j + i + 1]; j++)
        real_types[j] = (args_type_t)get_arg_type(array[j + i + 1]);
    act_ops = get_instruction(array[i], ops);
    instruction = build_instruction(act_ops, real_types, line_nb, array);
    list_append(parser->instructions, instruction);
}
