class UnionFind:
    def __init__(self, n):
        self.p, self.size, self.count = list(range(n)), [1] * n, n

    def find_set(self, i):
        if self.p[i] != i:
            self.p[i] = self.find_set(self.p[i])
        return self.p[i]

    def is_same_set(self, i, j):
        return self.find_set(i) == self.find_set(j)

    def union_set(self, i, j):
        x, y = self.find_set(i), self.find_set(j)
        if x != y:
            if self.size[y] > self.size[x]:
                x, y = y, x
            self.p[y] = x
            self.size[x] += self.size[y]
            self.size[y] = self.size[x]
            self.count -= 1
            return True
        return False
    
    def get_size(self, i):
        return self.size[self.p[i]]


if __name__ == "__main__":
    print("Assume that there are 5 disjoint sets initially\n")
    uf = UnionFind(5)
    uf.union_set(0, 1)
    uf.union_set(2, 1)
    uf.union_set(4, 3)
    uf.union_set(1, 2)
    a, b, c = uf.is_same_set(3, 4), uf.is_same_set(4, 0), uf.count
    print(a, b, c, uf.count)
