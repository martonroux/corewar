#!/bin/bash

folder="champions"

cor_string=".cor"

for file in "$folder"/*; do
    if [[ -f "$file" && "${file: -${#cor_string}}" != "$cor_string" ]]; then
        echo "=== File : $file ==="

        output=$(./asm "$file" && hexdump -C "${file::-1}cor")

        expected_output=$(./asm_correct "$file" && hexdump -C "${file::-1}cor")
        rm "${file::-1}cor"

        if [[ "$output" == "$expected_output" ]]; then
            echo "The test on $file was a success."
        else
            echo "Test failed on $file. Here are the results:"
            echo -ne "YOUR asm output : \n$output"
            echo -ne "EXPECTED asm output : \n$expected_output"
        fi

        echo "============================"
        echo
    fi
done

folder="./"

for file in "$folder"/*; do
    if [[ -f "$file" && "${file: -${#cor_string}}" == "$cor_string" ]]; then
      rm "$file"
    fi
done
