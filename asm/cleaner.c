/*
** EPITECH PROJECT, 2023
** cleaner
** File description:
** file for cleaner functions
*/

#include <stdlib.h>
#include "my.h"
#include "op.h"
#include <stdio.h>

char **clean_line(char *line)
{
    int i = 0;
    int j = 0;
    int past = 0;
    char *clean = malloc(sizeof(char) * my_strlen(line) + 1);

    if (line[0] == '\n') return NULL;
    for (; line[i] == ' ' || line[i] == '\t'; i++);
    while (line[i] && line[i] != '\n' && line[i] != COMMENT_CHAR) {
        if (line[i] == ' ' || line[i] == '\t')
            clean[j++] = ' ';
        else
            clean[j++] = line[i++];
        while ((line[i] == ' ' || line[i] == '\t') && past++ == i) i++;
        past = i;
    }
    if (clean[j - 1] == ' ') j--;
    clean[j] = '\0';
    if (clean[0] == '\0') return NULL;
    return my_str_to_word_array(clean);
}
