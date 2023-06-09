/*
** EPITECH PROJECT, 2023
** COREWAR
** File description:
** arguments.c
*/

#include "my.h"
#include "op.h"
#include "asm.h"
#include "transform.h"

void check_argument_type(char *instruction, char *arg,
                            int types, int arg_type)
{
    if (arg_type == -1)
        get_argument_error(instruction, arg, types, arg_type);
    if (arg_type == T_LAB) {
        if ((T_IND & types) != T_IND && (T_DIR & types) != T_DIR)
            get_argument_error(instruction, arg, types, arg_type);
    } else {
        if ((arg_type & types) != arg_type)
            get_argument_error(instruction, arg, types, arg_type);
    }
}

bool verif_command_arg(char **array, op_t *ops)
{
    int arg_type;
    int i = 1;
    int j = 0;
    int nb_args = ops->nbr_args;
    char *inst;

    for (; array[i - 1] == LABEL_PTR; i++);
    inst = array[i - 1];
    for (; array[i]; i++) {
        j++;
        if (j > nb_args)
            break;
        arg_type = get_arg_type(array[i]);
        check_argument_type(inst, array[i], ops->type[j - 1], arg_type);
    }
    if (j != nb_args)
        wrong_nb_args_error(j, nb_args, inst);
    return false;
}

void verif_argument(char ***array)
{
    op_t *ops = get_op_tab();
    op_t *act;
    char *name;
    char *err_msg;
    int j, i = 0;
    for (; array[i] && array[i][0] != LABEL_PTR && array[i][0][0] == '.'; i++);
    for (; array[i]; i++) {
        for (j = 0; array[i][j] == LABEL_PTR; j++);
        name = array[i][j];
        if (name == NULL) continue;
        act = get_instruction(name, ops);
        if (act == NULL) {
            err_msg = my_strcat("Unknown instruction: ", name);
            err_msg = my_strcat(err_msg, "\n");
            print_error(err_msg);
        }
        verif_command_arg(array[i], act);
    }
}
