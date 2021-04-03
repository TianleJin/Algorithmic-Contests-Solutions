from math import gcd
from fractions import Fraction
from collections import defaultdict
import random
iintl = lambda: list(map(int, input().strip().split()))


def search(pizzas, D):
    cand = sorted({Fraction(pizza, slices) for slices in range(1, D + 1) for pizza in pizzas})
    lo, hi = 0, len(cand)
    while lo + 1 < hi:
        mid = (lo + hi) >> 1
        slc = cand[mid]
        if sum(pizza * slc.denominator // slc.numerator for pizza in pizzas) >= D:
            lo = mid
        else:
            hi = mid
    return cand[lo]


def solve():
    _, D = iintl()
    pizzas = sorted(iintl())
    U = search(pizzas, D)
    cnts = defaultdict(int)
    full = defaultdict(int)
    for slices in range(1, D + 1):
        for pizza in pizzas:
            size = Fraction(pizza, slices)
            if size <= U:
                cnts[size] += slices
                if cnts[size] <= D:
                    full[size] += 1
    return D - max(full.values())


if __name__ == '__main__':
    T = int(input())
    for t in range(1, T + 1):
        print('Case #{}: {}'.format(t, solve()))