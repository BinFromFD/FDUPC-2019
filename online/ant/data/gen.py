#!/usr/bin/python3

from os import *
from random import *

def sh(x):
    print(f'> {x}')
    assert not system(x)

sh('g++ ../sources/std.cpp -O3 -o /tmp/exec')
idx = 0
for i in range(0, 51):
    idx += 1
    sh(f'echo {i} > {idx}.in')
    sh(f'/tmp/exec < {idx}.in > {idx}.ans')

for i in range(10):
    n = randint(100, 10**18)
    idx += 1
    sh(f'echo {n} > {idx}.in')
    sh(f'/tmp/exec < {idx}.in > {idx}.ans')
