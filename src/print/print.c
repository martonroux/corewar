/*
** EPITECH PROJECT, 2023
** print
** File description:
** file for print functions
*/

#include <stdarg.h>
#include <unistd.h>
#include "my.h"

static int exec_param(const char *str, va_list *ap, int i, int pt)
{
    char *params = "sdcx";
    char c = str[i];

    if (my_strchr(params, c)) {
        write(1, str + pt, i - pt - 1);
        if (c == 's')
            my_putstr(va_arg(*ap, char *));
        if (c == 'd')
            my_putnbr(va_arg(*ap, int));
        if (c == 'c')
            my_putchar(va_arg(*ap, int), 1);
        if (c == 'x')
            my_putnbr_base(va_arg(*ap, int), "0123456789ABCDEF");
        return 1;
    }
    return 0;
}

void print(char *str, ...)
{
    int i = 0;
    int pt = 0;
    va_list ap;

    va_start(ap, str);
    for (; str[i]; i++) {
        if (str[i] == '%' && exec_param(str, &ap, ++i, pt) == 1)
            pt = i + 1;
    }
    va_end(ap);
    write(1, str + pt, i - pt);
}
