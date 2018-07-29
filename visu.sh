#gshuf -i 1-$1 -n $1 | tr '\n' ' ' > range;

#ARG=$(cat range);
ARG=$1

make
echo $1
./push_swap $ARG  | ./checker $ARG  | ./view_stack $3
