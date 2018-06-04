
(for i in $(seq $1 $END);
do gshuf -i 0-20000 -n 1;
done) | tr '\n' ' ' > range;

ARG=$(cat range);

make
./push_swap $ARG | ./checker $ARG
