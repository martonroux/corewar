/*
** EPITECH PROJECT, 2023
** B-CPE-200-MPL-2-1-corewar-louis.rollet [WSL: Ubuntu]
** File description:
** main
*/

#include "parser.h"
#include "asm.h"
#include "champions.h"
#include "core_file.h"
#include "cw_arguments.h"
#include "instructions.h"
#include "my.h"
#include "op.h"
#include "transform.h"
#include "utils.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "corewar.h"

asm_t *parser = NULL;

void init_asm()
{
    FILE *file = fopen("tests/criterion_test/pdd.s", "r");

    if (!file)
        file = fopen("pdd.s", "r");
    parser = build_asm();
    char ***array = NULL;
    array = parse_header(file, parser);
    check_labels(array, parser);
    verif_argument(array);
    for (int i = 0; array[i]; i++)
        parse_body_line(array[i], i, parser);
    create_bytes(parser);
    set_instruction_values(parser);
}

corewar_t *corewar = NULL;

void init_corewar()
{
    char *argv[] = {"./corewar", "tests/criterion_test/bill.cor",
        "tests/criterion_test/helltrain.cor", NULL};
    int ac = 2;
    corewar = create_corewar(ac, argv);
    return corewar;
}

Test (name_command,have_name_and_comment, .init=init_asm)
{
    if (strcmp(parser->header.prog_name, "pdd") == 0)
        cr_assert(1);
}

Test (parse_header,have_commen, .init=init_asm)
{
    if (strcmp(parser->header.comment, "pdd") == 0)
        cr_assert(1);
}

Test (parse_header, good_size, .init=init_asm)
{
    if (parser->header.prog_size != 115)
        cr_assert(1);
}

Test (parse_label, good_label, .init=init_asm)
{
    node_t *tmp = parser->labels->head;
    char *name[] = {"begin", "live", "attack"};
    int i = 0;

    for (;tmp != NULL; tmp = tmp->next) {
        label_t *label = tmp->data;
        if (strcmp(label->name, name[i]) != 0) {
            cr_assert(0);
        }
        i++;
    }
}

Test (parse_instructions, good_instructions, .init=init_asm)
{
    node_t *tmp = parser->instructions->head;
    int i = 0;
    int code[] = {11,12,2,2,2,2,2,5,9,1,2,
        9,2,3,16,4,11,2,2,5,9};

    for (;tmp != NULL; tmp = tmp->next) {
        asm_instruction_t *instruction = tmp->data;
        if (instruction->code != code[i]) {
            cr_assert(0);
        }
        i++;
    }
}

Test (parse_instructions, good_code, .init=init_asm)
{
    node_t *tmp = parser->instructions->head;
    int i = 0;
    int code[] = {11,12,2,2,2,2,2,5,9,1,2,
        9,2,3,16,4,11,2,2,5,9};

    for (;tmp != NULL; tmp = tmp->next) {
        asm_instruction_t *instruction = tmp->data;
        if (instruction->code != code[i])
            cr_assert(0);
        i++;
    }
}

Test (parse_new_instructions, good_instructions, .init=init_asm)
{
    node_t *tmp = parser->instructions->head;
    int i = 0;
    int code[] = {11,12,2,2,2,2,2,5,9,1,2,
        9,2,3,16,4,11,2,2,5,9};

    for (;tmp != NULL; tmp = tmp->next) {
        asm_instruction_t *instruction = tmp->data;
        if (instruction->code != code[i])
            cr_assert(0);
        i++;
    }
}

Test (writer, write_all, .init=init_asm)
{
    FILE *file = fopen("tests/criterion_test/pdd.s", "r");
    if (!file)
        file = fopen("pdd.s", "r");
    write_parser(parser, "pdd.cor");
}

Test (help_flag, help)
{
    int n = asm_h_flag();
    if (n != 0)
        cr_assert(0);
}

Test (run, run_corewar)
{
    int ac = 2;
    char *av[] = {"./corewar", "pdd.cor"};

}

Test (linked_list, create_list)
{
    list_t *list = create_list();
    cr_assert_not_null(list);
}

Test (my_getnbr_base, getnbr_base)
{
    char *str = "123";
    int n = my_getnbr_base(str, "0123456789");
    cr_assert_eq(n, 123);
}

Test (clean_line, clean_line)
{
    char str[] = "test  123"; 
    char **array = clean_line(str);
    if (strcmp(array[0], "test") != 0)
        cr_assert(0);
    if (strcmp(array[1], "123") != 0)
        cr_assert(0);
}

Test (list_append, no_list)
{
    list_t *list = NULL;
    char *str = "test";
    list_append(list, str);
}

Test (list_remove, remove_list)
{
    list_t *list = create_list();
    char *str = "test";
    list_append(list, str);
    list_remove(list, 0, false);
}

Test (my_putchar, put_char)
{
    my_putchar('c', 0);
}

Test (my_char_count, char_count)
{
    char *str = "test";
    int n = my_char_count(str, 'e');
    cr_assert_eq(n, 1);
}

Test (my_str_str, str_str)
{
    char *str = "test";
    char *str2 = "es";
    char *n = my_strstr(str, str2);
    cr_assert_eq(n, str + 1);
}

Test (my_str_str, needle_bigger_haystack)
{
    char *str = "test";
    char *str2 = "testtest";
    char *n = my_strstr(str, str2);
    if (n == NULL)
        cr_assert(1);
}

Test (my_str_str, str_str_null)
{
    char *str = "test";
    char *str2 = "nono";
    char *n = my_strstr(str, str2);
    if (n == NULL)
        cr_assert(1);
}

Test (parse_header_name, name)
{
    int n = parse_header_name("name ", NULL, NULL, NULL);
    printf("%d\n", n);
}

Test (print, print)
{
    print("test %d, %s, %c, %x", 1, "test", 'c', 10);
}

Test (my_putnberr, putnberr)
{
    my_putnberr(10);
    my_putnberr(-10);
}

Test (my_putsterr, putsterr)
{
    my_putsterr("test");
}

Test (my_intcpy,intcpy)
{
    int i[] = {1,2,3,4,5};
    int *n = malloc(sizeof(int) * 5);

    my_intcpy(n, i, 5);
}

Test (my_getnbr, getnbr)
{
    char *str = "123";
    int n = my_getnbr(str);
    cr_assert_eq(n, 123);
}

Test (my_putnbr, negativ)
{
    my_putnbr(-10);
}

Test (my_putnbr, positiv)
{
    my_putnbr(1233);
}

Test (wrong_nb_args_error, not_enoug)
{
    int i = 2;
    int nb_args = 2;
    char *instruciton = "test";
    wrong_nb_args_error(i, nb_args, instruciton);
    cr_assert(1);
}

Test (my_memcpy, memcpy)
{
    char *str = "test";
    char *n = malloc(sizeof(char) * 5);
    my_memcpy(n, str, 5);
}

Test (print_debug, debug)
{
    print_debug("test");
    print_debug("test, %s, %d, %c", "test", 10, 'c');
}

Test (my_log, log)
{
    int i = my_log(12, 10);
    cr_assert_eq(i, 2);
}

Test(list_free, free)
{
    list_t *list = create_list();
    char *str = "test";
    list_append(list, str);
    list_free(list, false);
}

Test (is_alpha_num, alpha_num)
{
    char *str = "test";
    bool n = is_alpha_num(str);
    cr_assert_eq(n, true);
}

Test (is_alpha_numeric, alpha_numeric)
{
    char c = 'c';
    int n = is_alpha_numeric(c);
    cr_assert_eq(n, 2);
}

Test (destroy_all, destroy, .init=init_asm)
{
    char ***array = malloc(sizeof(char **) * 2);
    destroy_all(parser, array);
}

Test (list_remove_data, removed_data)
{
    list_t *list = create_list();
    char *str = "test";
    list_append(list, str);
    list_remove_data(list, str, false);
}

Test (init_asm, init)
{
    init_asm();
}

Test (my_putnbr_base, neg)
{
    my_putnbr_base(-10, "0123456789");
}

Test (get_pcb, pcb)
{
    args_type_t type[] = {1, 2, 3, 0};
    int n = get_pcb(type);
    cr_assert_eq(n, 108);
}

Test (handle_help_arg, help)
{
    handle_help_arg();
}

Test (corewar, create_corewar)
{
    char *argv[] = {"./corewar", "tests/criterion_test/bill.cor",
        "tests/criterion_test/bill.cor", NULL};
    int ac = 2;
    corewar_t *corewar = create_corewar(ac, argv);
    if (corewar == NULL)
        cr_assert(0);
}

Test (corewar, running_corewar)
{
    int check = 0;
    char *argv[] = {"./corewar", "tests/criterion_test/bill.cor",
        "tests/criterion_test/bill.cor", NULL};
    int ac = 2;
    corewar_t *corewar = create_corewar(ac, argv);
    run_corewar(corewar, &check);
    destroy_corewar(corewar);
}

Test (corewar, hell_train_vs_bill)
{
    char *argv[] = {"./corewar", "tests/criterion_test/bill.cor",
        "tests/criterion_test/helltrain.cor", NULL};
    int ac = 2;
    int check = 0;
    corewar_t *corewar = create_corewar(ac, argv);
    run_corewar(corewar, &check);
    destroy_corewar(corewar);
}

Test (corewar, instruction_ldi,.init=init_corewar)
{
    instruction_t *instruction = malloc(sizeof(instruction_t));
    instruction->args_type[2] = T_DIR;
    int i = instruction_ldi(corewar, instruction);
    cr_assert_eq(i, 1);
}

Test (handle_dump_arg,pos)
{
    corewar_arguments_t *args = malloc(sizeof(corewar_arguments_t));
    char *arg = "122200";
    handle_dump_arg(args, arg);
}

Test (print_padding, padding,.init = init_corewar)
{
    print_memory(corewar);
}

Test (is_alpha, is_alpha)
{
    char *str = "test";
    bool n = is_alpha(str);
    cr_assert_eq(n, true);
}

Test (is_alpha, is_alpha2)
{
    char *str = "__";
    bool n = is_alpha(str);
    cr_assert_eq(n, false);
}

Test (list_get_node, get_node)
{
    list_t *list = create_list();
    char *str = "test";
    list_append(list, str);
    node_t *node = list_get_node(list, 0);
    cr_assert_eq(node->data, str);
}

Test (instruction_and,return_0, .init = init_corewar)
{
    instruction_t *instruction = malloc(sizeof(instruction_t));
    instruction->args_type[0] = T_DIR;
    int i = instruction_and(corewar, instruction);
    cr_assert_eq(i, 1);
}

Test (instruction_st, st, .init = init_corewar)
{
    instruction_t *instruction = malloc(sizeof(instruction_t));
    instruction->args_type[0] = T_DIR;
    int i = instruction_st(corewar, instruction);
    cr_assert_eq(i, 1);
}

Test(read_next_bytes, read_0x7F)
{
    char single_byte[] = {0x7F};
    int n = read_next_bytes(single_byte, 1);
    cr_assert_eq(n, 127);
}

Test(read_next_bytes, read_FF00)
{
    char two_bytes[] = {0xFF, 0x00};
    int32_t n = read_next_bytes(two_bytes, 2);
    cr_assert_eq(n, 65280);
}

Test(read_next_bytes, read_FFFF0100)
{
    char four_bytes[] = {0xFF,0xFF,0x01, 0x00};
    int32_t n = read_next_bytes(four_bytes, 4);
    cr_assert_eq(n, -65280);
}

Test(read_next_bytes, read_0x12345678)
{
    char four_bytes[] = {0x12, 0x34, 0x56, 0x78};
    ulong n = read_next_bytes(four_bytes, 4);
    cr_assert_eq(n, 305419896);
}

Test(read_next_bytes, read_0x1F)
{
    char non_printable[] = {0x1F};
    int n = read_next_bytes(non_printable, 1);
    cr_assert_eq(n, 31);
}

Test (read_next_byes, read_A522)
{
    char two_bytes[] = {0xA5, 0x22};
    int n = read_next_bytes(two_bytes, 2);
    cr_assert_eq(n, 42274);
}

Test (read_next_byes, read_2832)
{
    char two_bytes[] = {0x28, 0x32};
    int n = read_next_bytes(two_bytes, 2);
    cr_assert_eq(n, 10290);
}