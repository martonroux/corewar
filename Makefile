##
## EPITECH PROJECT, 2023
## corewar
## File description:
## Wrapper for the sub-projects recipes.
##

MAKE_ASM:=$(MAKE) -C asm
MAKE_COREWAR:=$(MAKE) -C corewar
MAKE_RUN:= $(MAKE) -C tests/criterion_test
UNIT_TEST:= ./tests/criterion_test/criterion_test


export DCOM_COMPILE_CFLAGS+=$(CFLAGS)
export DCOM_COMPILE_CPPFLAGS+=$(CPPFLAGS)
export DCOM_COMPILE_LDFLAGS+=$(LDFLAGS)

all: liblist
	$(MAKE_ASM)
	$(MAKE_COREWAR)

clean:
	$(MAKE) -C lib/List clean
	$(MAKE_ASM) clean
	$(MAKE_COREWAR) clean
	$(MAKE_RUN) clean
	find . -type f -name "*.gcno" -delete
	find . -type f -name "*.gcda" -delete
	find . -type f -name "*.gcov" -delete

fclean: clean
	$(MAKE) -C lib/List fclean
	$(MAKE_ASM) fclean
	$(MAKE_COREWAR) fclean
	$(MAKE_RUN) fclean

re: fclean all

tests_run: liblist
	$(MAKE_RUN)
	$(UNIT_TEST)

liblist:
	$(MAKE) -C lib/List
