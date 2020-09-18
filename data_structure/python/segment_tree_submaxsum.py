import math


class node:
    def __init__(self, value):
        self.sum = value
        self.prefixsum = value
        self.suffixsum = value
        self.maxsum = value

    def __str__(self):
        return ",".join(map(str, (self.sum, self.prefixsum, self.suffixsum, self.maxsum)))


# find Largest Contiguous
# SubAay sum in a given range with updates
class SegmentTree:
    def __init__(self, N):
        # segment tree for N numbers
        self.tree = [node(0) for _ in range(2 * N + 1)]

    def build(self, A: list, lo: int, hi: int, i: int):
        if lo == hi:
            self.tree[i] = node(A[lo])
        else:
            mid, L, R = lo + (hi - lo >> 1), 2 * i + 1, 2 * i + 2
            self.build(A, lo, mid, L)
            self.build(A, mid + 1, hi, R)
            self.tree[i].sum = self.tree[L].sum + self.tree[R].sum
            self.tree[i].prefixsum = max(self.tree[L].prefixsum, self.tree[L].sum + self.tree[R].prefixsum)
            self.tree[i].suffixsum = max(self.tree[R].suffixsum, self.tree[R].sum + self.tree[L].suffixsum)
            self.tree[i].maxsum = max(self.tree[i].prefixsum, self.tree[i].suffixsum, self.tree[L].maxsum,
                                      self.tree[R].maxsum, self.tree[L].suffixsum + self.tree[R].prefixsum)

    def update(self, A: list, i: int, lo: int, hi: int, idx: int, value: int):
        if lo == hi:
            self.tree[i] = node(value)
        else:
            mid, L, R = lo + (hi - lo >> 1), 2 * i + 1, 2 * i + 2
            if idx <= mid:
                self.update(A, L, lo, mid, idx, value)
            else:
                self.update(A, R, mid + 1, hi, idx, value)
            self.tree[i].sum = self.tree[L].sum + self.tree[R].sum
            self.tree[i].prefixsum = max(self.tree[L].prefixsum, self.tree[L].sum + self.tree[R].prefixsum)
            self.tree[i].suffixsum = max(self.tree[R].suffixsum, self.tree[R].sum + self.tree[L].suffixsum)
            self.tree[i].maxsum = max(self.tree[i].prefixsum, self.tree[i].suffixsum, self.tree[L].maxsum,
                                      self.tree[R].maxsum, self.tree[L].suffixsum + self.tree[R].prefixsum)

    def query(self, A: list, i: int, lo: int, hi: int, l: int, r: int) -> node:
        if r < lo or hi < l:
            return node(-math.inf)
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
            result = node(-math.inf)
            result.sum = left.sum + right.sum
            result.prefixsum = max(left.prefixsum, left.sum + right.prefixsum)
            result.suffixsum = max(right.suffixsum, right.sum + left.suffixsum)
            result.maxsum = max(self.tree[i].prefixsum, self.tree[i].suffixsum, left.maxsum, right.maxsum,
                                left.suffixsum + right.prefixsum)
            return result


if __name__ == "__main__":
    a = [-2, -3, 4, -1, -2, 1, 5, -3]
    n = len(a)

    st = SegmentTree(n)

    # build the tree
    st.build(a, 0, n - 1, 0)


    # 1st query type-1
    l = 5
    r = 8
    print(st.query(a, 0, 0, n - 1, l - 1, r - 1).maxsum)

    # 2nd type-2 query
    index = 1
    value = 10
    a[index - 1] = value
    st.update(a, 0, 0, n - 1, index - 1, value)


    # 3rd type-1 query
    l = 1
    r = 3
    print(st.query(a, 0, 0, n - 1, l - 1, r - 1).maxsum)
