/*
** EPITECH PROJECT, 2023
** COREWAR
** File description:
** labels.c
*/

#include "my.h"
#include "asm.h"
#include "list.h"
#include <stdio.h>
#include <stddef.h>

label_t *get_label(char *label, asm_t *parser)
{
    node_t *node = parser->labels->head;
    label_t *data;
    while (node != NULL) {
        data = node->data;
        if (!my_strcmp(label, data->name))
            return data;
        node = node->next;
    }
    return NULL;
}

char *get_label_arg(char **array)
{
    for (int i = 0; array[i]; i++) {
        if (array[i] == LABEL_PTR)
            continue;
        if (array[i][0] == '%' && array[i][1] == ':')
            return array[i] + 2;
    }
    return NULL;
}

void check_labels(char ***array, asm_t *parser)
{
    char *label;
    char *error_msg;

    for (int i = 0; array[i]; i++) {
        label = get_label_arg(array[i]);
        if (label == NULL)
            continue;
        error_msg = my_strcat("Unreferenced label: [", label);
        error_msg = my_strcat(error_msg, "]\n");
        if (get_label(label, parser) == NULL)
            print_error(error_msg);
    }
}
