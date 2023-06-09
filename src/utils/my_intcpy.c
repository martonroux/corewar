/*
** EPITECH PROJECT, 2023
** COREWAR
** File description:
** my_intcpy.c
*/

void my_intcpy(int *dest, const int *src, int size)
{
    for (int i = 0; i < size; i++) {
        dest[i] = src[i];
    }
}
