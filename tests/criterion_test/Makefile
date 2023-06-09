##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile, don't forget to put CPPFLAGS and
## remove -Werror and backslash every src files
##

TARGET = criterion_test
SRC = $(shell find ../../asm -name "*.c" ! -name "main.c") \
	$(shell find ../../lib/List/src -name "*.c")\
	$(shell find ../../src -name "*.c") \
	$(shell find ../../corewar -name "*.c" ! -name "main.c") \
	test_parse.c
OBJ = $(SRC:.c=.o) 
CPPFLAGS = -I ../../include -I../../lib/List/src \
			-lcriterion --coverage -ftest-coverage -fprofile-arcs
LDFLAGS		=	-L../../lib/List

all	:	$(TARGET)

$(TARGET)	: $(OBJ)
	$(CC) $(SRC) -o $(TARGET) $(CPPFLAGS) $(LDFLAGS)
clean	:
	$(RM) $(OBJ)
	$(RM) *.gcno *.gcda *.gcov
fclean	:	clean
	$(RM) $(TARGET)
re	:	fclean all
