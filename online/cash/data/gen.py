#!/usr/bin/python3

from random import *

for i in range(1, 11):
    with open(f'{i}.in', 'w') as fp:
        fp.write(str(randint(1, 50000)))
