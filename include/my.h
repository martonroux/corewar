/*
** EPITECH PROJECT, 2023
** my
** File description:
** file for my functions
*/

#ifndef MY_H
    #define MY_H

    #include <stdbool.h>
    #include <stddef.h>
    #include <stdio.h>
    #include <stdlib.h>

    #define REV(X) \
        ((X << 24) | ((X & 0xff00) << 8) | ((X >> 8) & 0xff00) | (X >> 24))
    #define ABS(X) ((X < 0) ? (-X) : (X))

int my_strlen(const char *str);
int my_strcmp(char *str, char *str2);
char *my_strdup(char *str);
char *my_strndup(char *str, int n);
int my_strncmp(char *str, char *str2, int n);
int parse_header_name(char *str, int *i, char **array, int *j);
int parse_header_twice(char *str, int *i, char **array, int *j);
char *my_strnndup(char *str, int a, int b);
int my_char_count(char *str, char c);
char **my_str_to_word_array(char *str);
void my_strcpy(char *dest, char *src);
char *my_strchr(char *str, char c);
void parse_filename(char *file);
void print_error(const char *str, ...);
char *my_strcat(char *dest, char const *src);
char *create_filename(char *filename);
char *my_strstr(const char *haystack, const char *needle);
bool is_alpha_num(char const *str);
bool is_num(char const *str);
bool is_alpha(char const *str);
int my_atoi(char const *str);
int my_getnbr_base(char *str, char *base);
int my_getnbr(char *str);
void add_octet(int *octet, int position, int number);
void add_reg(int *octet, int position);
void add_dir(int *octet, int position);
void add_indir(int *octet, int position);
int is_alpha_numeric(char c);
void my_putsterr(char *str);
void my_putnberr(int nb);
void my_putchar(char c, int output);
void print_error2(const char *str, ...);
int is_little_endian(void);
char **clean_line(char *line);
void *my_memcpy(void *dest, const void *src, size_t n);
void my_intcpy(int *dest, const int *src, int size);
void print_debug(const char *str, ...);
void print(char *str, ...);
void my_putstr(char *str);
void my_putnbr(int nb);
void my_putnbr_base(int nbr, char const *base);
int my_log(int nb, int base);
void my_memset(void *ptr, char value, int size);

#endif
