it = lambda: list(map(int, input().strip().split()))


def solve():
    n = int(input())

    two = 0
    three = 0

    while n % 2 == 0:
        two += 1
        n = n // 2

    while n % 3 == 0:
        three += 1
        n = n // 3
    
    if two > three or n > 1:
        return -1
    
    return 2 * three - two


if __name__ == '__main__':
    T = int(input())
    for _ in range(T):
        print(solve())