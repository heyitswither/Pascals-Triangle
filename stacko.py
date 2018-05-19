#!/usr/bin/env python3
def choose(n, k):
    if k in (0, n):
        return 1
    return choose(n-1, k-1) + choose(n-1, k)

for row in range(50):
    for k in range(row + 1):
        print(choose(row, k), end=' ', flush=True)
    print()
