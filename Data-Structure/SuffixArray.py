from collections import namedtuple
from math import ceil, log2
from random import randint, choices
from string import ascii_lowercase
import timeit


class NaiveSuffixArray:
    """Naive implementation of suffix array O(N^2*log(N))"""
    def __init__(self, s):
        self.s = s
    
    def build_sa(self):
        s = self.s
        n = len(s)
        suf = [s[i:] for i in range(n)]
        self.arr = sorted(range(n), key=lambda i:suf[i])
    
    def build_lcp(self):
        s = self.s
        n = len(s)
        lcp = [0] * n
        sa = self.arr
        for i in range(n - 1):
            k = 0
            while sa[i] + k < n and sa[i + 1] + k < n and s[sa[i] + k] == s[sa[i + 1] + k]:
                k += 1
            lcp[i] = k
        self.lcp = lcp            


class DNCSuffixArray:
    """Divide and conquer implementation of suffix array with built-in sort O(N*log(N)^2) and radix sort O(N*log(N))"""
    def __init__(self, s):
        self.s = s

    def counting_sort(self, arr, n, k):
        A = max(n + 1, 27)

        tmp = [0] * n
        cnt = [0] * A
        for i in range(n):
            idx = arr[i][k]
            cnt[idx] += 1

        for i in range(1, A):
            cnt[i] += cnt[i - 1]
        
        for i in range(n - 1, -1, -1):
            idx = arr[i][k]
            tmp[cnt[idx] - 1] = arr[i]
            cnt[idx] -= 1
        
        for i in range(n):
            arr[i] = tmp[i]
    
    def radix_sort(self, arr):
        n, m = len(arr), len(arr[0]) - 1
        for k in range(m - 1, -1, -1):
            self.counting_sort(arr, n, k)

    def build_sa(self, use_radix_sort=False):
        if len(self.s) == 1:
            self.arr = [0]
            return

        Rank = namedtuple("Rank", ["r1", "r2", "idx"])
        s = self.s
        n = len(s)
        lvl = ceil(log2(n)) + 1
        arr = [[-1] * n for _ in range(lvl)]

        for i in range(n):
            arr[0][i] = ord(s[i]) - ord('a') + 1
        
        step = 1
        for i in range(1, lvl):
            comp = [
                Rank(arr[i - 1][j], arr[i - 1][j + step] if j + step < n else 0, j)
                for j in range(n)
            ]

            if use_radix_sort:
                self.radix_sort(comp)
            else:
                comp.sort()
            
            l = 0
            r = arr[i][comp[l].idx] = 1
            for j in range(1, n):
                if comp[j].r1 != comp[l].r1 or comp[j].r2 != comp[l].r2:
                    l = j
                    r += 1
                arr[i][comp[j].idx] = r
            step *= 2
        
        self.arr = [rank.idx for rank in comp]
    
    def build_lcp(self):
        s = self.s
        n = len(s)
        sa = self.arr
        lcp = [0] * n
        rnk = [0] * n
        for i in range(n):
            rnk[sa[i]] = i
        
        k = 0
        for i in range(n):
            if rnk[i] == n - 1:
                k *= 0
                continue

            j = sa[rnk[i] + 1]
            while i + k < n and j + k < n and s[i + k] == s[j + k]:
                k += 1
            lcp[rnk[i]] = k
            k = max(0, k - 1)
        self.lcp = lcp


if __name__ == "__main__":
    def gen_random_testcase(k, charset=ascii_lowercase):
        """Generates a random string of length k"""
        return "".join(choices(charset, k=k))


    def run_accuracy_test(test_cases):
        """Checks accuracy of dnc build_sa with naive build_sa"""
        print("Starting accuracy test")
        for case in test_cases:
            naive_suffix_array = NaiveSuffixArray(case)
            dnc_suffix_array = DNCSuffixArray(case)
            naive_suffix_array.build_sa()
            dnc_suffix_array.build_sa()
            naive_suffix_array.build_lcp()
            dnc_suffix_array.build_lcp()
            assert naive_suffix_array.arr == dnc_suffix_array.arr
            assert naive_suffix_array.lcp == dnc_suffix_array.lcp
        print("All implementations gave the same results")
    

    def run_performance_test(test_cases):
        """Compares runtime of building suffix array using built-in sort vs radix sort"""
        def run_built_in_sort():
            for case in test_cases:
                dnc_suffix_array = DNCSuffixArray(case)
                dnc_suffix_array.build_sa(use_radix_sort=False)
        
        def run_radix_sort():
            for case in test_cases:
                dnc_suffix_array = DNCSuffixArray(case)
                dnc_suffix_array.build_sa(use_radix_sort=True)
        
        print("Starting performance test")
        print(f"Suffix array with built-in sort - time: {timeit.timeit(run_built_in_sort, number=1)}s")
        print(f"Suffix array with radix sort - time: {timeit.timeit(run_radix_sort, number=1)}s")


    small_cases = ["a", "ab", "aaaa", "abcd", "abab", "abcabc", "aababb"] + [
        gen_random_testcase(randint(1, 50)) for _ in range(1000)
    ] + [
        gen_random_testcase(randint(50, 1000)) for _ in range(100)
    ] + [
        gen_random_testcase(randint(1, 500), "efg") for _ in range(1000)
    ]
    run_accuracy_test(small_cases)

    # large_cases = [
    #     gen_random_testcase(randint(10000, 100000)) for _ in range(10)
    # ]
    # run_performance_test(large_cases)
