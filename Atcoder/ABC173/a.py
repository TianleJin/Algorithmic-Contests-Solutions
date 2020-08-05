def solve():
    n = int(input())
    while n > 0:
        n -= 1000
    return -n


if __name__ == '__main__':
    print(solve())