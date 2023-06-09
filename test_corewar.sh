make re > /dev/null
make clean > /dev/null

# EXECUTE OUR COREWAR
./corewar/corewar "$@" > my_output.txt

# EXECUTE THE REAL COREWAR
./tests/corewar_check/corewar_correct "$@" > real_output.txt

# COMPARE THE OUTPUTS
 diff my_output.txt real_output.txt
