class LinkedList:
    def __init__(self, max_size=16):
        self.max_size = max_size + 1  # all nodes are 1-index based
        self.values = [0] * self.max_size  # self.values[0] is the dummy head node
        self.next = [0] * self.max_size  # next[last node]=0
        self.prev = [0] * self.max_size

    def insert_node(self, i, x):
        # insert node at x before node at i
        if i < 0 or i >= self.max_size or x < 0 or x >= self.max_size:
            return
        self.prev[x] = self.prev[i]
        self.next[x] = i
        self.next[self.prev[x]] = x
        self.prev[i] = x

    def delete_node(self, x):
        # delete node at x
        self.next[self.prev[x]] = self.next[x]
        self.prev[self.next[x]] = self.prev[x]

    def append(self, x):
        # append node at x
        self.insert_node(0, x)

    def set(self, i, value):
        # set value
        self.values[i] = value

    def __str__(self):
        cur = self.next[0]
        nodes = []
        if cur != 0:
            nodes.append(self.values[cur])
        while self.next[cur] != 0:
            nodes.append(self.values[cur])
            cur = self.next[cur]
        return ",".join([str(node) for node in nodes])


if __name__ == '__main__':
    sl = LinkedList()
    sl.append(1)
    sl.set(1, 1)
    sl.append(2)
    sl.set(2, 3)
    sl.insert_node(2, 3)
    sl.set(3, 5)
    print(str(sl))
