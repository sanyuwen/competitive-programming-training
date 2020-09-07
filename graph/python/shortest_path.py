import math
from queue import PriorityQueue

if __name__ == '__main__':
    edges = []
    with open("graph.txt") as f:
        for i, line in enumerate(f.readlines()):
            cur = (int(i) for i in line.split(' '))
            if i == 0:
                V, E, s = cur
            else:
                edges.append(tuple(cur))
    adjlist = [[] for _ in range(V)]
    for edge in edges:
        u, v, w = edge
        adjlist[u].append((v, w))
    print(adjlist)

    s = 3
    # dijkstra
    parent = [-1] * V
    distance = [math.inf] * V
    intree = [False] * V
    distance[s] = 0
    v = s
    while not intree[v]:
        intree[v] = True
        for p, w in adjlist[v]:
            new_dis = distance[v] + w
            if distance[p] > new_dis:
                distance[p] = new_dis
                parent[p] = v
        print(distance)
        if not all(intree):
            v, _ = min([(v, dis) for v, dis in enumerate(distance) if not intree[v]], key=lambda t: t[1])

    print("use heap")

    pq = PriorityQueue()
    parent = [-1] * V
    distance = [math.inf] * V
    distance[s] = 0
    v = s
    pq.put((0, s))
    while not pq.empty():
        dis, v = pq.get()
        if dis > distance[v]:
            continue
        for p, w in adjlist[v]:
            new_dis = distance[v] + w
            if distance[p] > new_dis:
                parent[p] = v
                pq.put((new_dis, p))
                distance[p] = new_dis
        print(distance)

    # dp
