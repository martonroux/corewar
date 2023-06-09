/*
** EPITECH PROJECT, 2023
** COREWAR
** File description:
** debug_print.c
*/

#include <stdarg.h>
#include <unistd.h>
#include "my.h"

static int exec_param_debug(const char *str, va_list *ap, int i, int pt)
{
    char *params = "sdc";
    char c = str[i];

    if (my_strchr(params, c)) {
        write(2, str + pt, i - pt - 1);
        if (c == 's')
            my_putsterr(va_arg(*ap, char *));
        if (c == 'd')
            my_putnberr(va_arg(*ap, int));
        if (c == 'c')
            my_putchar(va_arg(*ap, int), 2);
        return 1;
    }
    return 0;
}

void print_debug(const char *str, ...)
{
    int i = 0;
    int pt = 0;
    va_list ap;

    va_start(ap, str);
    for (; str[i]; i++) {
        if (str[i] == '%' && exec_param_debug(str, &ap, ++i, pt) == 1)
            pt = ++i;
    }
    va_end(ap);
    write(2, str + pt, i - pt);
}
