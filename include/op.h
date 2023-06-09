/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-corewar-louis.rollet
** File description:
** op
*/

#ifndef _OP_H_
    # define _OP_H_

    #include <stdint.h>
    #include "list.h"

    # define MEM_SIZE                (6 * 1024) /* modulo of the index < */
    # define IDX_MOD                 512
    /* this may not be changed 2 ^ * IND_SIZE */
    # define MAX_ARGS_NUMBER         4

    # define COMMENT_CHAR            '#'
    # define LABEL_CHAR              ':'
    # define DIRECT_CHAR             '%'
    # define SEPARATOR_CHAR          ','

    # define LABEL_CHARS             "abcdefghijklmnopqrstuvwxyz_0123456789"

    # define NAME_CMD_STRING         ".name"
    # define COMMENT_CMD_STRING      ".comment"

    # define REG_NUMBER      16              /* r1 <--> rx */

    # define T_REG           1       /* register */
    # define T_DIR           2       /* direct  (ld  #1,r1  put 1 into r1) */
    # define T_IND           4       /* indirect always relative
                                   ( ld 1,r1 put what's in the address (1+pc)
                                   into r1 (4 bytes )) */
    # define T_LAB           8       /* LABEL */

    # define REG_SIZE        1
    # define IND_SIZE        2
    # define DIR_SIZE2       2
    # define DIR_SIZE4       4
    # define DIR_SIZE(x) ((x) == 32 ? (DIR_SIZE4) : (DIR_SIZE2))

    # define PROG_NAME_LENGTH        128
    # define COMMENT_LENGTH          2048

    # define COREWAR_EXEC_MAGIC      0xea83f3

    /* number of cycle before beig declared dead */
    # define CYCLE_TO_DIE    1536
    # define CYCLE_DELTA     5
    # define NBR_LIVE        40


typedef char    args_type_t;


typedef struct op_s {
    char        *mnemonique;
    int         nbr_args;
    args_type_t type[MAX_ARGS_NUMBER];
    char        code;
    int         nbr_cycles;
    int         direct_size;
    bool pcb;
} op_t;

typedef struct header_s {
    int  magic;
    char prog_name[PROG_NAME_LENGTH + 1];
    int32_t  prog_size;
    char comment[COMMENT_LENGTH + 1];
} header_t;

typedef struct label_s {
    char *name;
    int pos;
    int byte;
} label_t;

typedef struct asm_instruction_s {
    char **line;
    char code;
    int line_nb;
    int nb_args;
    int direct_size;
    int pcb;
    int args[MAX_ARGS_NUMBER];
    args_type_t real_type[MAX_ARGS_NUMBER];
} asm_instruction_t;

typedef struct asm_s {
    header_t header;
    list_t *labels;
    list_t *instructions;
} asm_t;

#endif
