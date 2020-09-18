diameter of tree: max of all shortest paths between node pairs
[1] 2 DFS:
    from any node, dfs finds farthest node1, another dfs finds farthest node2, we want shortest distance between node1 and node2.
[2] DP on tree:
    from any node to its children, get farthest distance d1, second farthest distance d2. we want max(d1+d2) for all nodes.
time: O(n)