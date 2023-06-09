/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-corewar-louis.rollet [WSL: Ubuntu]
** File description:
** read_header
*/

#include <sys/types.h>
#include "my.h"
#include "op.h"

static int reverse_int(uint nb)
{
    uint res = 0;

    res |= (nb & 0xFF) << 24;
    res |= (nb & 0xFF00) << 8;
    res |= (nb & 0xFF0000) >> 8;
    res |= (nb & 0xFF000000) >> 24;
    return (int) res;
}

header_t *read_header(FILE *file)
{
    header_t *header = malloc(sizeof(header_t));

    fread(header, sizeof(header_t), 1, file);
    header->magic = reverse_int(header->magic);
    header->prog_size = reverse_int(header->prog_size);
    if (header->magic != COREWAR_EXEC_MAGIC)
        print_error("Invalid magic number.\n");
    return header;
}
