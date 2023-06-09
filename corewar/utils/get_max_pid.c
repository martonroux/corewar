/*
** EPITECH PROJECT, 2023
** COREWAR
** File description:
** get_new_pid.c
*/

#include "corewar.h"
#include "list.h"

instruction_t *get_instr_with_pid(corewar_t *corewar, int pid)
{
    node_t *node = corewar->instructions->head;
    instruction_t *instruction = NULL;

    while (node != NULL) {
        instruction = (instruction_t *) node->data;
        if (instruction->pid == pid)
            return instruction;
        node = node->next;
    }
    return NULL;
}

int get_max_pid(corewar_t *corewar)
{
    node_t *node = corewar->instructions->head;
    instruction_t *instruction = NULL;
    int value = 0;

    while (node != NULL) {
        instruction = (instruction_t *) node->data;
        value = (instruction->pid > value) ? instruction->pid : value;
        node = node->next;
    }
    node = corewar->instr_to_add->head;
    while (node != NULL) {
        instruction = (instruction_t *) node->data;
        value = (instruction->pid > value) ? instruction->pid : value;
        node = node->next;
    }
    return value;
}
