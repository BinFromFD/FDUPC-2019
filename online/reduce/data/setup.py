#!/usr/bin/python3

from os import *

def sh(x):
    print(f'> {x}')
    assert not system(x)

sh('g++ ../sources/std.cpp -O3 -o /tmp/exec')
sh('/tmp/exec < 1.in > 1.ans')
for i in range(2, 11):
    sh(f'python3 ./gen.py 10000 100000 > {i}.in')
    sh(f'/tmp/exec < {i}.in > {i}.ans')
for i in range(11, 21):
    sh(f'python3 ./gen.py 1000000000 1000000000 > {i}.in')
    sh(f'/tmp/exec < {i}.in > {i}.ans')