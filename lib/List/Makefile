##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile to compile list lib
##

CC = gcc
CFLAGS = -W -Wall -Wextra -Werror -I. -g3

SRC = $(wildcard src/*.c) \
		$(wildcard format_parser/*.c)
OBJ = $(SRC:.c=.o)
TARGET = liblist.a
LDFLAGS		=	-L../lib/List -llist

all: $(TARGET)

$(TARGET): $(OBJ)
	$(AR) rsc $(TARGET) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all
