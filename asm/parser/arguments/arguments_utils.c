/*
** EPITECH PROJECT, 2023
** COREWAR
** File description:
** arguments_utils.c
*/

#include "my.h"
#include "op.h"
#include "asm.h"
#include <stddef.h>

int get_arg_type(char *arg)
{
    int reg;

    if (is_num(arg))
        return T_IND;
    reg = my_atoi(arg += 1);
    arg -= 1;
    if (arg[0] == 'r' && reg > 0 && reg <= REG_NUMBER && is_num(arg + 1))
        return T_REG;
    if (arg[0] == DIRECT_CHAR && arg[1] == LABEL_CHAR)
        return T_DIR;
    if (arg[0] == LABEL_CHAR)
        return T_IND;
    if (arg[0] == DIRECT_CHAR && is_num(arg + 1))
        return T_DIR;
    return -1;
}

op_t *get_instruction(char *str, op_t *ops)
{
    for (int i = 0; ops[i].mnemonique; i++) {
        if (!my_strcmp(str, ops[i].mnemonique))
            return &ops[i];
    }
    return NULL;
}

int get_argument_value(char *arg, asm_t *parser, int line_nb)
{
    label_t *label;

    if (is_num(arg))
        return my_atoi(arg);
    if (arg[0] == 'r')
        return my_atoi(arg + 1);
    if (arg[0] == DIRECT_CHAR && is_num(arg + 1))
        return my_atoi(arg + 1);
    if ((arg[0] == DIRECT_CHAR && arg[1] == LABEL_CHAR) ||
        arg[0] == LABEL_CHAR) {
        if (arg[0] == LABEL_CHAR)
            arg += 1;
        else
            arg += 2;
        label = get_label(arg, parser);
        if (label == NULL)
            print_error("Label not found in linked list: [%s].\n", arg);
        return label->byte - get_bytes_at_line(parser, line_nb);
    }
    return 0;
}
