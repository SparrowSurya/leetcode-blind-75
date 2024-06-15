from typing import List
from collections import deque

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        rows, cols = len(grid),len(grid[0])
        visited = set()

        def bfs(row, col):
            queue = deque([(row, col)])
            while queue:
                r, c = queue.popleft()

                for dr, dc in ((-1, 0), (1, 0), (0, -1), (0, 1)):
                    nr, nc = r+dr, c+dc
                    if (
                        nr in range(rows)
                        and nc in range(cols)
                        and grid[nr][nc] == '1'
                        and (nr, nc) not in visited
                    ):
                        queue.append((nr, nc))
                        visited.add((nr, nc))

        islands = 0
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == '1' and (r, c) not in visited:
                    bfs(r, c)
                    islands += 1
        return islands
