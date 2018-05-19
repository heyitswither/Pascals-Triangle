#!/usr/bin/env python3
import sys

tri = []

def main(rows):
    for i in range(0,rows+1):
        cur = []
        print(" "*(rows-i), end="")
        for y in range(i):
            if y in (0, i):
                cur.append(1)
                print(1, end=' ', flush=True)
            else:
                try:
                    cur.append(tri[i-1][y] + tri[i-1][y-1])
                    print(tri[i-1][y] + tri[i-1][y-1], end=' ', flush=True)
                except IndexError:
                    cur.append(1)
                    print(1, end=' ', flush=True)
        print()
        tri.append(cur)

if __name__ == "__main__":
    if len(sys.argv) > 1:
        if sys.argv[1].isdigit:
            main(int(sys.argv[1]))
        else:
            print("rows must be an integer")
    else:
        print("Usage: %s <rows>" % (sys.argv[0]))
