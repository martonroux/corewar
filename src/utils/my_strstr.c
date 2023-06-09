/*
** EPITECH PROJECT, 2023
** COREWAR
** File description:
** my_strstr.c
*/

#include "my.h"
#include <stdbool.h>
#include <stddef.h>

bool needle_correct(const char *needle, const char *haystack, int j, int i)
{
    if (needle[j] == '\0')
        return false;
    if (haystack[i + j] == '\0')
        return false;
    if (needle[j] != haystack[i + j])
        return false;
    return true;
}

char *my_strstr(const char *haystack, const char *needle)
{
    int j;
    for (int i = 0; haystack[i]; i++) {
        for (j = 0; needle_correct(needle, haystack, j, i); j++);
        if (needle[j] == '\0')
            return (char *)&haystack[i];
    }
    return NULL;
}
