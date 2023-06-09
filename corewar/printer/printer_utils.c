/*
** EPITECH PROJECT, 2023
** COREWAR
** File description:
** printer_utils.c
*/

#include "corewar.h"
#include "transform.h"
#include "my.h"

bool is_process_on_byte(corewar_t *corewar, int byte)
{
    instruction_t *instruction = NULL;

    for (node_t *node = corewar->instructions->head; node; node = node->next) {
        instruction = (instruction_t *) node->data;

        if (instruction->memory_pos == byte)
            return true;
    }
    return false;
}

void print_blank(bool had_instr)
{
    if (had_instr) {
        print("        ");
    } else {
        print("                                  ");
    }
}

void print_instruction(corewar_t *corewar, int offset)
{
    node_t *node = list_get_node(corewar->instructions, offset - 2);
    instruction_t *instruction = NULL;

    if (node == NULL)
        return print_blank(false);
    instruction = (instruction_t *) node->data;
    if (instruction->instruction == 0)
        return;
    op_t op = get_op_tab()[(int) instruction->instruction - 1];

    print("\t\t%s ", op.mnemonique);
    for (int i = 0; i < op.nbr_args; i++) {
        print("%d", instruction->args[i]);
        if (i < op.nbr_args - 1)
            print(",");
    }
    print("    \x1B[0mCycles left: %d", instruction->cycles);
    print_blank(true);
}

void print_general_data(corewar_t *corewar, int index, int max_per_line)
{
    int offset = 0;
    int nb_process = 0;

    if (index % max_per_line != max_per_line - 1)
        return;
    for (node_t *node = corewar->instructions->head; node; node = node->next,
        nb_process++);
    for (; index > max_per_line; offset++, index -= max_per_line);
    if (offset == 0)
        print("\t\t\x1B[0mCycle nb: %d      ", corewar->cycle);
    if (offset == 1)
        print("\t\t\x1B[0mNumber of processes: %d          ", nb_process);
    if (offset > 1)
        print_instruction(corewar, offset);
}

void print_byte_colors(corewar_t *corewar, int index)
{
    char str[17] = "0123456789ABCDEF";
    char *colors[5] = {"\x1B[0m", "\x1B[0;31m", "\x1B[0;32m", "\x1B[0;33m",
                    "\x1B[0;34m"};

    print(colors[(int) corewar->memory_owner[index]]);
    if (is_process_on_byte(corewar, index))
        print("\033[36m");
    print("%c%c ", str[(corewar->memory[index] >> 4) & 0xF],
            str[corewar->memory[index] & 0xF]);
    print("\033[0m");
}
