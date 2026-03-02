#!/bin/bash
for input in "2 1" "3 2 1" "9 8 7 6" "65 78 56 98" "100 50 75 25"; do
    echo -n "$input: "
    ./a.out $input | wc -l | tr -d ' '
    echo " operations"
done
