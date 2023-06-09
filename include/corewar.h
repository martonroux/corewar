/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** file for corewar functions
*/

#ifndef COREWAR_H
    #define COREWAR_H

    #include <stdint.h>
    #include "cw_arguments.h"
    #include "list.h"
    #include "op.h"
    #include <unistd.h>

typedef struct corewar_s corewar_t;
typedef struct instruction_s instruction_t;
typedef int (*instruction_callback)
    (corewar_t *corewar, instruction_t *instruction);

typedef struct champion_s {
    header_t *header;
    uint32_t registers[16];
    int id;
    bool carry;
} champion_t;

typedef struct instruction_s {
    champion_t *champion;
    char instruction;
    int memory_pos;
    int cycles;

    int args[4];
    int args_type[4];
    int size;
    int pid;
} instruction_t;

typedef struct corewar_s {
    corewar_arguments_t *args;
    list_t *instructions;
    list_t *instr_to_add;
    list_t *champions;

    char memory[MEM_SIZE + 1];
    char memory_owner[MEM_SIZE + 1];
    header_t *headers[4];
    int cycle_to_die;
    int lives[4];
    int total_lives;
    int cycle;
    int last_live;
} corewar_t;

corewar_t *create_corewar(int ac, char **av);
int run_corewar(corewar_t *corewar, int *checks);
void destroy_corewar(corewar_t *corewar);
header_t *read_header(FILE *file);
void print_memory(corewar_t *corewar);
void print_colorful_memory(corewar_t *corewar);
void run_loop(corewar_t *corewar);

/* INSTRUCTIONS */

instruction_callback *get_instruction_callbacks(void);
instruction_t *create_instruction(char instruction, int memory_pos);
void build_instr_to_add(corewar_t *corewar);
void kill_instructions(corewar_t *corewar);
void exec_instruction(corewar_t *corewar, instruction_t *instruction);
bool check_instruction_args(instruction_t *instruction);
int *read_instruction_type_pcb(int nb);
int *read_instruction_type_nopcb(void);
int32_t read_next_bytes(const char *memory, int bytes);
void get_instruction_args(corewar_t *corewar, instruction_t *instruction);
void debug_print_instruction(instruction_t *instruction, corewar_t *corewar);
bool check_instruction_args_reg(instruction_t *instruction);
void write_in_memory(corewar_t *corewar, int pc, int value, int bytes);
int get_max_pid(corewar_t *corewar);
instruction_t *get_instr_with_pid(corewar_t *corewar, int pid);
void first_read_instruction(corewar_t *corewar, instruction_t *instruction);
void update_instr_args(corewar_t *corewar, instruction_t *instruction);
void get_instruction_arg_type(corewar_t *corewar, instruction_t *instruction);
int get_instruction_size(char code, instruction_t *instruction);

#endif
