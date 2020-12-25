#!/bin/bash
gcc homework2.c -o homework2

echo Input the file path

read path

echo ascending\(-a\) or descending\(-d\)?

read ad

echo alpha-numeric\(-alpha\) or numeric\(-num\)?

read compare

./homework2 $path $ad $compare

rm homework2