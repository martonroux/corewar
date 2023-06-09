##
## EPITECH PROJECT, 2023
## asm
## File description:
## Makefile for the asm project.
##

SRC_DIR		=	.
GLOB_DIR	=	../src
SRC			=	$(shell find $(SRC_DIR) -name "*.c") \
				$(shell find $(GLOB_DIR) -name "*.c")
OBJ			=	$(SRC:.c=.o)

CFLAGS		+=	-Wall -Wextra -Werror
CPPFLAGS	+=	-I../include -I../lib/List/src
LDFLAGS		+=	-L../lib/List -llist

TARGET		=	asm

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(TARGET)

re: fclean all
