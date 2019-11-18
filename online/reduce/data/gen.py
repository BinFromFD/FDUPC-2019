#!/usr/bin/python3

from sys import *
from random import *

n, m = map(int, argv[1:])
a = randint(1, n)
b = randint(1, n)
r = randint(1, m)
print(f'{a * r}/{b * r}')