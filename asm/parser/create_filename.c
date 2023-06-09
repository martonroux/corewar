/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-corewar-louis.rollet [WSL: Ubuntu]
** File description:
** create_filename
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>

char *create_filename(char *filename)
{
    int len = my_strlen(filename);
    char *new = malloc(sizeof(char) * (len + 3));
    int i = 0;

    if (filename[len - 2] == '.' && filename[len - 1] == 's')
        filename[len - 2] = 0;
    for (; filename[i]; i++)
        new[i] = filename[i];
    new[i] = '\0';
    return my_strcat(new, ".cor");
}
