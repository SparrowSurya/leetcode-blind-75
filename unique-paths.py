class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        table = [[0 for _ in range(n + 1)] for _ in range(m + 1)]
        table[1][1] = 1

        for i in range(1, m + 1):
            for j in range(1, n + 1):
                table[i][j] += table[i - 1][j] + table[i][j - 1]

        return table[m][n]
