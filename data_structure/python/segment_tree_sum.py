import math


# find Largest Contiguous
# SubAay sum in a given range with updates
class SegmentTree:
    def __init__(self, N):
        # segment tree for N numbers
        self.tree = [0 for _ in range(2 * N + 1)]

    def build(self, A: list, lo: int, hi: int, i: int):
        if lo == hi:
            self.tree[i] = A[lo]
        else:
            mid, L, R = lo + (hi - lo >> 1), 2 * i + 1, 2 * i + 2
            self.build(A, lo, mid, L)
            self.build(A, mid + 1, hi, R)
            self.tree[i] = self.tree[L] + self.tree[R]

    def update(self, A: list, i: int, lo: int, hi: int, idx: int, value: int):
        if lo == hi:
            self.tree[i] = value
        else:
            mid, L, R = lo + (hi - lo >> 1), 2 * i + 1, 2 * i + 2
            if idx <= mid:
                self.update(A, L, lo, mid, idx, value)
            else:
                self.update(A, R, mid + 1, hi, idx, value)
            self.tree[i] = self.tree[L] + self.tree[R]

    def query(self, A: list, i: int, lo: int, hi: int, l: int, r: int):
        if r < lo or hi < l:
            return -math.inf
        elif l <= lo and hi <= r:
            return self.tree[i]
        else:
            mid, L, R = lo + (hi - lo >> 1), 2 * i + 1, 2 * i + 2
            if l > mid:
                return self.query(A, R, mid + 1, hi, l, r)
            elif r <= mid:
                return self.query(A, L, lo, mid, l, r)
            right = self.query(A, R, mid + 1, hi, l, r)
            left = self.query(A, L, lo, mid, l, r)
            return left + right

