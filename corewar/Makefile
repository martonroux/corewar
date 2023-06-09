##
## EPITECH PROJECT, 2023
## corewar
## File description:
## Makefile for the corewar project.
##

SRC_DIR		=	.
GLOB_DIR	=	../src
SRC			=	$(shell find $(SRC_DIR) -name "*.c") \
				$(shell find $(GLOB_DIR) -name "*.c")
OBJ			=	$(SRC:.c=.o)

CFLAGS		=	-Wall -Wextra -Werror -g3
CPPFLAGS	=	-I../include -I../lib/List/src
LDFLAGS		=	-L../lib/List -llist

TARGET		=	corewar

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

clean:
	$(RM) $(OBJ)
	$(RM) *.gcno *.gcda

fclean: clean
	$(RM) $(TARGET)

re: fclean all
