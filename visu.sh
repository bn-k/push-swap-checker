gshuf -i 1-$2 -n $1 | tr '\n' ' ' > range;

ARG=$(cat range);

make
./push_swap $ARG | ./checker $ARG | ./view_stack $3
