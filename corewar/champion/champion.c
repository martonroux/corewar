/*
** EPITECH PROJECT, 2023
** champion
** File description:
** file for champion functions
*/

#include <stdlib.h>
#include "corewar.h"
#include "champions.h"
#include "my.h"

champion_t *create_champion(header_t *header)
{
    champion_t *champion = malloc(sizeof(champion_t));

    *champion = (champion_t) {0};
    champion->header = header;
    return champion;
}

int check_adresses(char *memory, int addresses, int size)
{

    for (int i = addresses; i < addresses + size; i++)
        if (memory[i % MEM_SIZE] != 0)
            return 84;
    return 0;
}

void place_champions(corewar_t *corewar, champion_t *champion, int size, int pc)
{
    if (!corewar->args->champions[champion->id])
        return;
    pc *= (MEM_SIZE / corewar->args->nb_champions);
    if (corewar->args->load_address[champion->id] != -1)
        pc = corewar->args->load_address[champion->id];
    if (check_adresses(corewar->memory, pc, size) == 84)
        print_error("Invalid load address\n");
    fread(corewar->memory + pc,
        sizeof(char), size, corewar->args->champions[champion->id]);
    my_memset(corewar->memory_owner + pc, (char) (champion->id + 1), size);
    instruction_t *instruction =
        create_instruction(corewar->memory[pc], pc);
    instruction->champion = champion;
    first_read_instruction(corewar, instruction);
    list_append(corewar->instructions, instruction);
}

void load_champions(corewar_t *corewar)
{
    champion_t *champion = NULL;
    int placed = 0;

    for (int i = 0; i < 4; i++) {
        if (!corewar->args->champions[i])
            continue;
        champion = create_champion(read_header(corewar->args->champions[i]));
        champion->id = i;
        champion->registers[0] = i;
        list_append(corewar->champions, champion);
        corewar->headers[i] = champion->header;
        place_champions(corewar, champion, champion->header->prog_size,
                        placed++);
    }
}
