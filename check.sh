
gshuf -i 0-$2 -n $1 | tr '\n' ' ' > range;

ARG=$(cat range);
###cat range;

make
./push_swap $ARG | ./checker $ARG
