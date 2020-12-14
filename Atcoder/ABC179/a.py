it = lambda: list(map(int, input().strip().split()))


def solve():
    s = input().strip()
    return s + ('es' if s[-1] == 's' else 's') 


if __name__ == '__main__':
    print(solve())