from math import log
from typing import Callable


class SparseTable:
    def __init__(self, N: int, arr: [int], function: Callable):
        self.n = N
        self.k = 1 + int(log(N, 2))
        self.st = [[0] * self.n for _ in range(self.k + 1)]
        self.func = function
        self.arr = arr

    def pre_compute(self):
        for i in range(self.n):
            self.st[i][0] = self.func([self.arr[i]])
        for j in range(1, self.k + 1):
            i = 0
            while i + (1 << j) <= self.n:
                self.st[i][j] = self.func([self.st[i][j - 1], self.st[i + (1 << j - 1)][j - 1]])
                i += 1


def range_sum_queries(n: int, arr: [int], L: int, R: int):
    spt = SparseTable(n, arr, sum)
    ans = 0
    for j in range(spt.k, -1, -1):
        if 1 << j <= R - L + 1:
            ans += spt.st[L][j]
            L += 1 << j
    return ans


def range_minimal_queries(n: int, arr: [int], L: int, R: int):
    spt = SparseTable(n, arr, min)
    j = int(log(R - L + 1, 2))
    return min(spt.st[L][j], spt.st[R - (1 << j) + 1][j])