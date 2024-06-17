from typing import List

class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        graph = {i: [] for i in range(n)}

        for a, b in edges:
            graph[a].append(b)
            graph[b].append(a)

        visited = [False for _ in range(n)]

        def visit(node: int, prev: int):
            if visited[node]:
                return

            visited[node] = True
            for adj in graph[node]:
                visit(adj, node)

        count = 0
        for i, adj_list in graph.items():
            if visited[i]:
                continue

            count += 1
            visit(i, -1)

        return count
