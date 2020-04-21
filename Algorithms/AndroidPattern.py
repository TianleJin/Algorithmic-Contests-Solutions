from functools import lru_cache

def android_pattern(m, n):
    need_to_check = {(1, 7), (2, 8), (3, 9), (1, 3), (4, 6), (7, 9), (1, 9), (3, 7)}
    
    @lru_cache()
    def dfs(history, curr_num, curr_l):
        ans = (m <= curr_l <= n)
        for num in range(1, 10):
            if curr_num != num and not (history & (1 << num)):
                pair = (num, curr_num) if num < curr_num else (curr_num, num)
                if pair in need_to_check:
                    average = (curr_num + num) >> 1
                    if history & (1 << average):
                        ans += dfs(history | 1 << num, num, curr_l + 1)
                else:
                    ans += dfs(history | 1 << num, num, curr_l + 1)
        return ans
            
    return 4 * dfs(2, 1, 1) + 4 * dfs(4, 2, 1) + dfs(32, 5, 1)


if __name__ == "__main__":
    m = 4
    n = 9
    ans = android_pattern(m, n)
    print('There are total of {} android password patterns between length of {} - {}.'.format(ans, m, n))
