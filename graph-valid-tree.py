from typing import List

class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        graph = {i: [] for i in range(n)}
        
        for a, b in edges:
            graph[a].append(b)
            graph[b].append(a)

        visited = [False for _ in range(n)]

        def isTree(node: int, prev: int) -> bool:
            if visited[node]:
                return False

            visited[node] = True
            for adj in graph[node]:
                if adj == prev:
                    continue
                if not isTree(adj, node):
                    return False

            return True

        return isTree(0, -1) and all(visited)
