/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-corewar-louis.rollet
** File description:
** my_header_parser
*/

#include "my.h"
#include "op.h"

int parse_header_name(char *str, int *i, char **array, int *j)
{
    int len_str = my_strlen(str);
    if (my_strncmp(str, NAME_CMD_STRING, 5) == 0){
        array[(*j)++] = my_strdup(NAME_CMD_STRING);
        if (str[5] != ' ' || str[6] != '"' || str[len_str - 1] != '"'){
            return 84;
        } else {
            array[(*j)++] = my_strndup(str + 7, len_str - 6);
            array[(*j) - 1][my_strlen(array[(*j) - 1]) - 1] = 0;
            *i += 5;
            return 1;
        }
    }
    return 84;
}

int parse_header_twice(char *str, int *i, char **array, int *j)
{
    int len_str = my_strlen(str);
    int error = parse_header_name(str, i, array, j);
    if (my_strncmp(str, COMMENT_CMD_STRING, 8) == 0){
        array[(*j)++] = my_strdup(COMMENT_CMD_STRING);
        if (str[8] != ' ' || str[9] != '"' || str[len_str - 1] != '"'){
            return 84;
        } else {
            array[(*j)++] = my_strndup(str + 10, len_str - 9);
            array[(*j) - 1][my_strlen(array[(*j) - 1]) - 1] = 0;
            *i += 8;
            return 1;
        }
    }
    return error;
}
