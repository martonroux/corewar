/*
** EPITECH PROJECT, 2023
** TESTER
** File description:
** to_test.c
*/

int my_atoi(char const *str)
{
    int nb = 0;
    int sign = 1;
    int found = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == '-')
            sign = -sign;
        while (str[i] >= '0' && str[i] <= '9') {
            nb *= 10;
            nb += str[i] - '0';
            found = 1;
            i++;
        }
        if (found)
            break;
    }
    return nb * sign;
}
