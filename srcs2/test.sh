#!/bin/bash
i=0
b=:
c=:
while (($i < 30))
do
clear
echo $b
b=$b$c
sleep 0.1
i=$(($i + 1))
done
