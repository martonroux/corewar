/*
** EPITECH PROJECT, 2023
** callbacks
** File description:
** file for callbacks functions
*/

#include "corewar.h"
#include "instructions.h"

instruction_callback *get_instruction_callbacks(void)
{
    static instruction_callback callbacks[16] = {
        instruction_live, instruction_ld, instruction_st, instruction_add,
        instruction_sub, instruction_and, instruction_or, instruction_xor,
        instruction_zjmp, instruction_ldi, instruction_sti, instruction_fork,
        instruction_lld, instruction_lldi, instruction_lfork, instruction_aff
    };
    return callbacks;
}
