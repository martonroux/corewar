/*
** EPITECH PROJECT, 2023
** asm
** File description:
** file for asm functions
*/

#ifndef ASM_H
    #define ASM_H

    #include "op.h"
    #include <stdio.h>
    #include <stdlib.h>
    #define LABEL_PTR (char *) 1

asm_t *build_asm(void);
label_t *build_label(char *name, int pos);
asm_instruction_t *build_instruction(
    op_t *ops,
    args_type_t const real_type[MAX_ARGS_NUMBER],
    int line_nb,
    char **line
    );
int get_pcb(args_type_t const real_type[MAX_ARGS_NUMBER]);
void destroy_all(asm_t *parser, char ***array);
int create_core_file(asm_t *parser);
void check_labels(char ***array, asm_t *parser);
void verif_argument(char ***array);
void get_argument_error(char *instruction, char *conflict,
                            int types, int conf_type);
void wrong_nb_args_error(int j, int nb_args, char *inst);
op_t *get_instruction(char *str, op_t *ops);
int get_arg_type(char *arg);
label_t *get_label(char *label, asm_t *parser);
int get_argument_value(char *arg, asm_t *parser, int line_nb);
void write_args(asm_instruction_t *instruction, FILE *file);
void create_bytes(asm_t *parser);
int get_bytes_at_line(asm_t *parser, int line);
void set_instruction_values(asm_t *parser);
int asm_h_flag(void);
int read_core(char *filename, asm_t *my_asm);
int32_t rev_endian32(int32_t num);
int16_t rev_endian16(int16_t nb);
void write_dir(int nb, int bytes, FILE *file);
void write_name(asm_t *parse, FILE *file);
void write_2bytes(int nb, FILE *file);

#endif
