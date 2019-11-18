#!/usr/bin/python3

from argparse import ArgumentParser

argpr = ArgumentParser()
argpr.add_argument('file')
args = argpr.parse_args()

with open(args.file, 'rb') as fp:
    data = fp.read()

def to_char(c):
    if c == (255, 0, 0):
        return 'o'
    if c == (0, 0, 255):
        return '+'
    return '.'

pixels = list(zip(data[0::3], data[1::3], data[2::3]))
for i in range(0, 19):
    print(''.join(map(to_char, pixels[i * 19:(i +1) * 19])))