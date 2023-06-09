/*
** EPITECH PROJECT, 2023
** my_str_to_word_array
** File description:
** file for my str to word array functions
*/

#include <stdlib.h>
#include <stdbool.h>
#include "my.h"
#include <stdio.h>
#include "op.h"

int parse_label(char *str, int *i, char **array, int *j)
{
    int temp = *i;
    for (;my_strchr(LABEL_CHARS, str[temp]) != NULL; temp++);
    if (str[temp] == ':'){
        *i = temp;
        array[(*j)++] = my_strndup(str, *i + 1);
    } else if (str[temp] == ' ' && str[temp + 1] == ':'){
        return 84;
    }
    if (str[*i] == ' ' || str[*i] == '\t' || str[*i] == ':')
        (*i)++;
    return 0;
}

int parse_function(char *str, int *i, char **array, int *j)
{
    if (str[*i] == ' ' || str[*i] == '\t' || str[*i] == ':')
        (*i)++;
    if (str[*i] == '\0')
        return 0;
    int temp = *i;
    int a = *i;
    for (;is_alpha_numeric(str[temp]) == 2; temp++);
    if (!str[temp])
        return 84;
    if (str[temp] == ' ' || str[temp] == '%'){
        *i = temp;
        array[(*j)++] = my_strnndup(str, a, *i);
    }
    return 0;
}

int parse_argument(char *str, int *i, char **array, int *j)
{
    if (str[*i] == '\0')
        return 0;
    if (str[*i] == ' ' || str[*i] == '\t') (*i)++;
    if (str[*i] == ',') (*i)++;
    if (str[*i] == ' ' || str[*i] == '\t') (*i)++;
    int temp = *i, a = *i;
    for (;is_alpha_numeric(str[temp]) == 2 || str[temp] == '%' ||
    is_alpha_numeric(str[temp]) == 1 || str[temp] == ':'
    || str[temp] == '-'; temp++);
    if (str[temp - 1] == '%'){
        temp++;
        for (;is_alpha_numeric(str[temp]) == 2 || str[temp] == '%' ||
        is_alpha_numeric(str[temp]) == 1 || str[temp] == ':'
        || str[temp] == '-'; temp++);
    }
    if (str[temp] == ' ' || str[temp] == ',' || str[temp] == '\0'){
        *i = temp;
        array[(*j)++] = my_strnndup(str, a, *i);
    }
    return 0;
}

char **my_str_to_word_array(char *str)
{
    char **array = malloc(sizeof(char *) * (8));
    int j = 0, error = 0, i = 0;
    if (str[0] == '.')
        error = parse_header_twice(str, &i, array, &j);
    if (error == 1){
        array[j] = NULL;
        return array;
    }
    if (error == 84) print_error("An error occurred in parser!\n");
    if (my_strchr(LABEL_CHARS, str[0]) != NULL)
        parse_label(str, &i, array, &j);
    error = parse_function(str, &i, array, &j);
    for (; i <= my_strlen(str); i++)
        error = parse_argument(str, &i, array, &j);
    array[j] = NULL;
    if (error) print_error("An error occurred in parser!\n");
    return array;
}
