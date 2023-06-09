#!/bin/bash

folder="src/"

for file in "$folder"/*; do
    if [[ -f "$file" ]]; then
        echo "=== File : $file ==="

        output=$(./corewar "$file" "$file" -dump 5000)

        expected_output=$(./corewar_correct "$file" "$file" -dump 5000)

        if [[ "$output" == "$expected_output" ]]; then
            echo "The test on $file was a success."
        else
            echo "Test failed on $file. Here are the results:"
            echo -ne "YOUR corewar output : \n$output"
            echo -ne "EXPECTED corewar output : \n$expected_output"
        fi

        echo "============================"
        echo
    fi
done
