/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-corewar-louis.rollet
** File description:
** instructions
*/

#include "corewar.h"

#ifndef INSTRUCTIONS_H_
    #define INSTRUCTIONS_H_


int instruction_live(corewar_t *corewar, instruction_t *instruction);
int instruction_ld(corewar_t *corewar, instruction_t *instruction);
int instruction_st(corewar_t *corewar, instruction_t *instruction);
int instruction_add(corewar_t *corewar, instruction_t *instruction);
int instruction_sub(corewar_t *corewar, instruction_t *instruction);
int instruction_and(corewar_t *corewar, instruction_t *instruction);
int instruction_or(corewar_t *corewar, instruction_t *instruction);
int instruction_xor(corewar_t *corewar, instruction_t *instruction);
int instruction_zjmp(corewar_t *corewar, instruction_t *instruction);
int instruction_ldi(corewar_t *corewar, instruction_t *instruction);
int instruction_sti(corewar_t *corewar, instruction_t *instruction);
int instruction_fork(corewar_t *corewar, instruction_t *instruction);
int instruction_lld(corewar_t *corewar, instruction_t *instruction);
int instruction_lldi(corewar_t *corewar, instruction_t *instruction);
int instruction_lfork(corewar_t *corewar, instruction_t *instruction);
int instruction_aff(corewar_t *corewar, instruction_t *instruction);

#endif
