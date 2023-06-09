#!/bin/bash
##
## EPITECH PROJECT, 2023
## B-CPE-200-MPL-2-1-corewar-louis.rollet [WSL: Ubuntu]
## File description:
## test_corewar
##


compare_binaries() {
    ./"corewar" "$@"
    ./"corewar_correct" "$@"
    if [ "$output1" == "$output2" ]; then
        echo "OK"
    else
        echo "KO"
    fi
}

compare_binaries