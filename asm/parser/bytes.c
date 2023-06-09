/*
** EPITECH PROJECT, 2023
** COREWAR
** File description:
** bytes.c
*/

#include "op.h"
#include "asm.h"

int get_args_bytes(asm_instruction_t *instruction)
{
    int val = 1;
    int type;

    for (int i = 0; i < instruction->nb_args; i++) {
        type = (int)instruction->real_type[i];
        if (type == T_IND)
            val += IND_SIZE;
        if (type == T_DIR)
            val += DIR_SIZE(instruction->direct_size);
        if (type == T_REG)
            val += REG_SIZE;
    }
    if (instruction->pcb > 0)
        val += 1;
    return val;
}

int get_bytes_at_label(asm_t *parser, int line)
{
    node_t *actual = parser->instructions->head;
    asm_instruction_t *data;
    int total_bytes = 0;

    while (actual) {
        data = actual->data;
        if (data->line_nb >= line)
            break;
        total_bytes += get_args_bytes(data);
        actual = actual->next;
    }
    return total_bytes;
}

int get_bytes_at_line(asm_t *parser, int line)
{
    node_t *actual = parser->instructions->head;
    asm_instruction_t *data;
    int total_bytes = 0;

    while (actual) {
        data = actual->data;
        if (data->line_nb >= line)
            break;
        total_bytes += get_args_bytes(data);
        actual = actual->next;
    }
    return total_bytes;
}

void set_instruction_values(asm_t *parser)
{
    node_t *actual = parser->instructions->head;
    asm_instruction_t *inst_data;
    int i;

    while (actual) {
        inst_data = actual->data;
        for (i = 0; inst_data->line[i] == LABEL_PTR; i++);
        i++;
        for (int j = 0; j < inst_data->nb_args; j++, i++) {
            inst_data->args[j] = get_argument_value(
                inst_data->line[i],
                parser,
                inst_data->line_nb
                );
        }
        actual = actual->next;
    }
}

void create_bytes(asm_t *parser)
{
    node_t *actual = parser->labels->head;
    label_t *label_data;
    asm_instruction_t *inst_data;
    int total_size = 0;

    while (actual) {
        label_data = actual->data;
        label_data->byte = get_bytes_at_label(parser, label_data->pos);
        actual = actual->next;
    }
    actual = parser->instructions->head;
    while (actual) {
        inst_data = actual->data;
        total_size += get_args_bytes(inst_data);
        actual = actual->next;
    }
    parser->header.prog_size = total_size;
}
