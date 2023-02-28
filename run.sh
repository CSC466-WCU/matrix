#!/bin/bash

gcc -o mm mm.c
gcc -mavx2 -o imm imm.c

for i in 512 1024 2048
do
  echo "Matrix ${i}x${i}" 
  ./mm $i
  ./imm $i 
done
 
