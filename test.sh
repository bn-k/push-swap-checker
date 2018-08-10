
gshuf -i 0-$1 -n $1 | tr '\n' ' ' > range;

ARG=$(cat range);
###cat range;

make
./push_swap $ARG
