#!/usr/bin/python3

from sys import *
from random import *

n, m, S, K = map(int, argv[1:])

Σ = "abcdefghijlmnopqrstuvwxyz"[:S]
T = ''.join(choice(Σ) for i in range(m))
L = []
cnt = 0
while cnt < n:
    op = randint(2, 2)
    if op == 1:
        L.append(choice(Σ))
        cnt += 1
    else:
        rep = randint(1, K)
        L.append(T * K)
        cnt += m * K

P = ''.join(L)
print(P[:n])
print(T)