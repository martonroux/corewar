/*
** EPITECH PROJECT, 2023
** asm
** File description:
** file for asm functions
*/

#include <stdlib.h>
#include "asm.h"

asm_t *build_asm(void)
{
    asm_t *asm_ = malloc(sizeof(asm_t));

    asm_->header = (header_t) {0};
    asm_->labels = create_list();
    asm_->instructions = create_list();
    return asm_;
}

label_t *build_label(char *name, int pos)
{
    label_t *label = malloc(sizeof(label_t));

    label->name = name;
    label->pos = pos;
    return label;
}

asm_instruction_t *build_instruction(
        op_t *ops,
        args_type_t const real_type[MAX_ARGS_NUMBER],
        int line_nb,
        char **line
        )
{
    asm_instruction_t *instruction = malloc(sizeof(asm_instruction_t));

    *instruction = (asm_instruction_t) {0};
    instruction->code = ops->code;
    instruction->line_nb = line_nb;
    instruction->nb_args = ops->nbr_args;
    instruction->direct_size = ops->direct_size;
    instruction->line = line;
    instruction->pcb = (ops->pcb == true) ? get_pcb(real_type) : 0;
    for (int i = 0; i < ops->nbr_args; i++) {
        instruction->args[i] = 0;
        instruction->real_type[i] = real_type[i];
    }
    return instruction;
}

void destroy_all(asm_t *parser, char ***array)
{
    for (int i = 0; array[i]; i++) {
        if (array[i][0] != LABEL_PTR)
            free(array[i][0]);
        free(array[i]);
    }
    free(array);
    list_free(parser->labels, true);
    list_free(parser->instructions, true);
    free(parser);
}
