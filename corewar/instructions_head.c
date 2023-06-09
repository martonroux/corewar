/*
** EPITECH PROJECT, 2023
** COREWAR
** File description:
** instructions_head.c
*/

#include "corewar.h"

void exec_instruction(corewar_t *corewar, instruction_t *instruction)
{
    instruction_callback *callbacks = get_instruction_callbacks();

    update_instr_args(corewar, instruction);
    if (instruction->instruction != 0x00) {
        callbacks[(int) instruction->instruction - 1](corewar, instruction);
        if (instruction->instruction != 0x09)
            instruction->memory_pos += instruction->size;
        instruction->memory_pos %= MEM_SIZE;
    } else {
        instruction->memory_pos++;
        instruction->memory_pos %= MEM_SIZE;
    }
    first_read_instruction(corewar, instruction);
}

void kill_instructions(corewar_t *corewar)
{
    instruction_t *instruction = NULL;
    node_t *temp = NULL;

    for (node_t *node = corewar->instructions->head; node;) {
        instruction = (instruction_t *) node->data;
        if (corewar->lives[instruction->champion->id] == 0) {
            temp = node->next;
            list_remove_node(corewar->instructions, node, true);
            node = temp;
            continue;
        }
        node = node->next;
    }
    for (int i = 0; i < 4; i++)
        corewar->lives[i] = 0;
}

void build_instr_to_add(corewar_t *corewar)
{
    node_t *node = corewar->instr_to_add->head;
    instruction_t *instruction = NULL;

    while (node != NULL) {
        instruction = node->data;
        list_append(corewar->instructions, instruction);
        node = node->next;
        list_remove(corewar->instr_to_add, 0, false);
    }
}
