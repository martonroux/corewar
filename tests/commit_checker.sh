#!/bin/bash

# clean directory
make fclean > /dev/null
rm -rf cmake-build-debug/

# change the path of the coding-style-checker if needed
errors=$(~/Documents/DATA/coding-style-checker/coding-style.sh . . | tail -n 1 | cut -d ' ' -f 15,17,19)

# Check for coding style errors
if [ "$errors" != "0 0 0" ]
then
    echo "Coding style errors detected!"
    cat coding-style-reports.log
    exit 1
else
    echo "Coding style check success!"
fi
rm -f coding-style-reports.log

# Check for compilation errors
if [ "$(make re > /dev/null && echo $?)" == 0 ]
then
    echo "Compilation success!"
else
    echo "Compilation failed!"
    exit 1
fi

#if [ "$(make tests_run > /dev/null && echo $?)" == 0 ]
#then
#    echo "Tests success!"
#else
#    echo "Tests failed!"
#    exit 1
#fi

FORBIDDEN_FILES="*.o *.out *.a"
ALLOWED_FUNCTIONS="open fopen read fread write fwrite getline lseek fseek close fclose malloc realloc free exit"
ASM_FUNCTIONS=$(nm -u asm/asm | cut -d '@' -f 1 | cut -d ' ' -f 19 | grep -v "_")
CW_FUNCTIONS=$(nm -u corewar/corewar | cut -d '@' -f 1 | cut -d ' ' -f 19 | grep -v "_")

# Check forbidden functions from asm functions and corewar functions in allowed functions
# shellcheck disable=SC1073
for function in $ASM_FUNCTIONS
do
    if [ "$(echo "$ALLOWED_FUNCTIONS" | grep "$function" | wc -l)" == "0" ]
    then
        echo "Forbidden function $function detected!"
        exit 1
    fi
done

# shellcheck disable=SC1073
for function in $CW_FUNCTIONS
do
    if [ "$(echo "$ALLOWED_FUNCTIONS" | grep "$function" | wc -l)" == "0" ]
    then
        echo "Forbidden function $function detected!"
        exit 1
    fi
done

echo "No forbidden functions detected!"

# Check forbidden files
# shellcheck disable=SC1073
make fclean > /dev/null
exit 0
