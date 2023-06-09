/*
** EPITECH PROJECT, 2023
** COREWAR
** File description:
** run_loop.c
*/

#include "corewar.h"
#include "my.h"
#include "bonus.h"

static void finish_execution(corewar_t *corewar)
{
    if (corewar->args->dump >= 0) print_memory(corewar);
    if (corewar->last_live == -1) return;
    print("Le joueur %d (%s) a gagné.\n", corewar->last_live + 1,
            corewar->headers[corewar->last_live]->prog_name);
}

static int count_different_champions(corewar_t *corewar)
{
    int champions_cnt[4] = {0};
    int nb_champions = 0;

    for (node_t *node = corewar->instructions->head; node; node = node->next) {
        instruction_t *instruction = node->data;
        champions_cnt[instruction->champion->id]++;
    }
    for (int i = 0; i < 4; i++)
        if (champions_cnt[i] > 0) nb_champions++;
    return nb_champions;
}

void run_loop(corewar_t *corewar)
{
    int checks = 0;

    while (count_different_champions(corewar) > 0 &&
        (corewar->args->dump < 0 || corewar->cycle < corewar->args->dump)) {
        if (corewar->args->debug && corewar->cycle % 5 == 0)
            printer(corewar, 192, 96);
        if (run_corewar(corewar, &checks) == -1)
            break;
    }
    finish_execution(corewar);
}
