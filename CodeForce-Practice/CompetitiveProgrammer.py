def div60(s):
    digitSum = even = zeros = 0
    for ch in s:
        ch = int(ch)
        digitSum += ch
        if ch == 0:
            zeros += 1
        if ch % 2 == 0:
            even += 1
    if even > 1 and zeros and digitSum % 3 == 0:
        return "red"
    return "cyan"


if __name__ == "__main__":
    n = int(input())
    for _ in range(n):
        ans = div60(input())
        print(ans)