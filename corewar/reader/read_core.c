/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-corewar-louis.rollet [WSL: Ubuntu]
** File description:
** read_file
*/

#include "my.h"
#include "asm.h"
#include "parser.h"
#include "../../include/op.h"

int read_core(char *filename, asm_t *my_asm)
{
    int fd = open(filename, O_RDONLY);
    ssize_t bytesRead = read(fd, &my_asm->header, sizeof(struct header_s));

    if (bytesRead == -1) {
        close(fd);
        return 84;
    }

    close(fd);
    return 0;
}
